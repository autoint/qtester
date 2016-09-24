from distutils.core import setup
import py2exe
import sys
from glob import glob

sys.path.append("C:\\zzz_devl\\QTester\\version_7\\dep")

myDataFiles = [
	      ("Microsoft.VC90.CRT", glob(r'C:\zzz_devl\QTester\version_7\dep\*.*')),
	      ("Microsoft.VC90.MFC", glob(r'C:\zzz_devl\QTester\version_7\dep\*.*')),
	      ("phonon_backend", glob(r'C:\Python27\Lib\site-packages\PySide\plugins\phonon_backend\*.*'))
	      ]

setup(windows=[{"script" : "QTester.py"}], data_files=myDataFiles )

 
#setup(console=['pysideVideo.py'])`

