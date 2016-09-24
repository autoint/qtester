from PySide import QtGui, QtCore
from PySide.phonon import Phonon
import time
import re

class Window(QtGui.QWidget):
    def __init__(self):
        QtGui.QWidget.__init__(self)
        self.setWindowTitle('QTester')
        self.media = Phonon.MediaObject(self)
        self.video = Phonon.VideoWidget(self)
        self.video.setMinimumSize(400, 400)
        self.audio = Phonon.AudioOutput(Phonon.VideoCategory, self)
        Phonon.createPath(self.media, self.audio)
        Phonon.createPath(self.media, self.video)
        self.buttonChoose = QtGui.QPushButton('Choose Playlist', self)
        #self.buttonMimes = QtGui.QPushButton('Show Mimetypes', self)
        self.slider = Phonon.VolumeSlider(self)
        self.slider.setAudioOutput(self.audio)
        layout = QtGui.QGridLayout(self)
        layout.addWidget(self.video, 0, 0, 1, 2)
        layout.addWidget(self.buttonChoose, 1, 0)
        #layout.addWidget(self.buttonMimes, 1, 1)
        layout.addWidget(self.slider, 2, 0, 1, 2)
        layout.setRowStretch(0, 1)
        self.media.stateChanged.connect(self.handleStateChanged)
        self.buttonChoose.clicked.connect(self.handleButtonChoose)
        #self.buttonMimes.clicked.connect(self.handleButtonMimes)
	self.playlist = [] 
	self.playlistNode = 0
	self.playlistLastNode = 0
	self.results = []
	self.installEventFilter(self)
	self.inputReceived = False

    def eventFilter(self, widget, event):
	if (self.media.state() == Phonon.PlayingState) and (event.type() == QtCore.QEvent.KeyPress):
            key = chr(event.key()).lower()
            if key == self.playlist[self.playlistNode][2 * int(self.playlist[self.playlistNode][9])].lower():
	        self.results.append([self.playlist[self.playlistNode][0], key, self.media.currentTime(), 'TRUE'])
	    else:
	        self.results.append([self.playlist[self.playlistNode][0], key, self.media.currentTime(), 'FAIL'])
	    self.inputReceived = True
            self.media.pause()
            return True
        return QtGui.QWidget.eventFilter(self, widget, event)


    def handleButtonChoose(self):
        if self.media.state() == Phonon.PlayingState:
            self.media.stop()
        else:
            dialog = QtGui.QFileDialog(self)
            dialog.setFileMode(QtGui.QFileDialog.ExistingFile)
            if dialog.exec_() == QtGui.QDialog.Accepted:
                path = dialog.selectedFiles()[0]
		counter = 0
		with open(path, "r") as ins:
		   self.playlist[:] = []
                   for line in ins:
		      line = re.sub(r',\s', ',', line).split(',')
		      print "the line => "
		      print line
		      self.playlist.append(line)
                      counter = counter + 1
	        self.playlistNode = 0
	        self.playlistLastNode = counter
                self.handleButtonMimes(self.playlist[self.playlistNode])
		self.media.setCurrentSource(Phonon.MediaSource( self.playlist[self.playlistNode][0]))
		print "playing ===> " +  self.playlist[self.playlistNode][0]
                self.media.play()
            dialog.deleteLater()

    def handleButtonMimes(self, Options):
        dialog = OptionsDialog(self, Options)
        dialog.exec_()

    def handleStateChanged(self, newstate, oldstate):
        if newstate == Phonon.PlayingState:
            self.buttonChoose.setText('Stop')
        elif ((newstate == Phonon.PausedState) and (oldstate ==  Phonon.PlayingState)):
	    if self.inputReceived != True:
	        self.results.append([self.playlist[self.playlistNode][0], '0', self.media.currentTime(), 'FAIL'])
            self.playlistNode = self.playlistNode + 1
	    if self.playlistNode < self.playlistLastNode:
                self.media.setCurrentSource(Phonon.MediaSource( self.playlist[self.playlistNode][0]))
	        print "playing ===> " +  self.playlist[self.playlistNode][0] 
                #self.handleButtonMimes(self.playlist[self.playlistNode])
                self.media.play()
		self.inputReceived = False
	    else:
	        self.media.stop()
	        print self.results
		with open("results" + time.strftime("%Y%m%d-%H%M%S") + ".dat", "w") as outs:
		    for line in self.results:			
                        outs.write(line[0] + ', ' + line[1] + ', ' + str(line[2]) + ', ' + line[3] + '\n' )
		self.results[:] = []
        elif (newstate != Phonon.LoadingState and
              newstate != Phonon.BufferingState):
            self.buttonChoose.setText('Choose File')
            if newstate == Phonon.ErrorState:
                source = self.media.currentSource().fileName()
                print ('ERROR: could not play: %s' % source)
                print ('  %s' % self.media.errorString())

class OptionsDialog(QtGui.QDialog ):
    def __init__(self, parent, Options):
        QtGui.QDialog.__init__(self, parent)
        self.setAttribute(QtCore.Qt.WA_DeleteOnClose)
        self.setWindowTitle('Video Options')
        listbox = QtGui.QListWidget(self)
        listbox.setSortingEnabled(False)
	print Options
        listbox.addItems([Options[1] + " => " + Options[2]] )
        listbox.addItems([Options[3] + " => " + Options[4]] )
        listbox.addItems([Options[5] + " => " + Options[6]] )
        listbox.addItems([Options[7] + " => " + Options[8]] )
        layout = QtGui.QVBoxLayout(self)
        layout.addWidget(listbox)
        self.resize(300, 100)

if __name__ == '__main__':

    import sys
    app = QtGui.QApplication(sys.argv)
    app.setApplicationName('QTester')
    window = Window()
    window.show()
    sys.exit(app.exec_())

