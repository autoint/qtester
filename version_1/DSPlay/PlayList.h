

#include <stdio.h>
#include <string.h>

#define MAX_PLAYLIST_LENGTH 100
#define MAX_PATH_LENGTH 1024
#define MAX_LABEL_LENGTH 32
#define MAX_OPTION_POSSIBLE 4

class PlayList
{
public:

	typedef struct 
	{
		char FileToPlay[MAX_PATH_LENGTH];
		char  OptionLabel[MAX_OPTION_POSSIBLE][MAX_LABEL_LENGTH];
		char  OptionCommand[MAX_OPTION_POSSIBLE];
		char  CorrectOptionNumber;

	} tPlayListItem;

	tPlayListItem PlayListList[MAX_PLAYLIST_LENGTH];

	PlayList(void);
	~PlayList(void);
	int ReadPlayList(char* FileName);
	int NextItemOnPlayList(tPlayListItem *FileName);
	bool CreatePlaylist(char* FileName);

private:

	int current_item;
	FILE * hFile;
	
};
