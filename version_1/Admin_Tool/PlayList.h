#pragma once


#include "afxcmn.h"

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
		bool  Valid;

	} tPlayListItem;

	tPlayListItem PlayListList[MAX_PLAYLIST_LENGTH];

	PlayList();
	~PlayList(void);
	int ReadPlayList(char * Buffer, int Length);
	int NextItemOnPlayList(tPlayListItem *FileName);
	int InitPlayList(CFile *FileHandle);
	int RewindPlayList();
	int AddItemOnPlayList(tPlayListItem Item);
	int PrepareDumpFile(char * Buffer);

private:

	int current_item;
	CFile *hFile;
	
};

