#include ".\playlist.h"


PlayList::PlayList(void)
{
	hFile = (FILE *) NULL;
}

PlayList::~PlayList(void)
{
}

int PlayList::ReadPlayList(char* FileName)
{
	
	current_item = 0;
	fopen_s(&hFile, FileName, "r+");
	if (hFile == NULL)
	{
		while(1);
	}
	else
	{
		for(int i = 0; i < MAX_PLAYLIST_LENGTH; i++)
		{
			if (fscanf(hFile, "%s %s %c %s %c %s %c %s %c %d\n", 
					PlayListList[i].FileToPlay,
					PlayListList[i].OptionLabel[0],
					&PlayListList[i].OptionCommand[0],
					PlayListList[i].OptionLabel[1],
					&PlayListList[i].OptionCommand[1],
					PlayListList[i].OptionLabel[2],
					&PlayListList[i].OptionCommand[2],
					PlayListList[i].OptionLabel[3],
					&PlayListList[i].OptionCommand[3],
					&PlayListList[i].CorrectOptionNumber) == EOF)
			{
					i = MAX_PLAYLIST_LENGTH;
			}
		}
	}
	return 0;
}

int PlayList::NextItemOnPlayList(tPlayListItem *Item)
{
	memcpy((void *) Item, (const void *) &(PlayListList[current_item].FileToPlay), sizeof(tPlayListItem));
	current_item++;
	return 0;
}

bool PlayList::CreatePlaylist(char* FileName)
{
	bool vReturnStatus = false;
	if (FileName != NULL)
	{
		fopen_s(&hFile, FileName, "w+");
		if (hFile != NULL)
		{
			vReturnStatus = true;
		}	
	}

	return vReturnStatus;
}
