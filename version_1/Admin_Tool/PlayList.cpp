#include "PlayList.h"
#include <stdio.h>


PlayList::PlayList()
{
	
}

PlayList::~PlayList(void)
{
}

int PlayList::InitPlayList(CFile *FileHandle)
{
	hFile = new CFile(FileHandle);
	return 0;
}


int PlayList::ReadPlayList(char * Buffer, int Length)
{
	current_item = 0;
	int current_pos = 0;

	for(int i = 0; i < MAX_PLAYLIST_LENGTH; i++)
	{
		int returnvalue=0;

		returnvalue = sscanf(&(Buffer[current_pos]), "%s %s %c %s %c %s %c %s %c %d\n", 
													PlayListList[i].FileToPlay,
													PlayListList[i].OptionLabel[0],
													&PlayListList[i].OptionCommand[0],
													PlayListList[i].OptionLabel[1],
													&PlayListList[i].OptionCommand[1],
													PlayListList[i].OptionLabel[2],
													&PlayListList[i].OptionCommand[2],
													PlayListList[i].OptionLabel[3],
													&PlayListList[i].OptionCommand[3],
													&PlayListList[i].CorrectOptionNumber);
		
		if(returnvalue < 10)
		{
			break;
		}
		PlayListList[current_item].Valid = true;
		for(current_pos++; (current_pos < (Length-1)) && (Buffer[current_pos] != '\n'); current_pos++);

		if ( current_pos == (Length-1))
		{
			i = MAX_PLAYLIST_LENGTH;
		}
		else
		{
			current_pos++;
		}
		current_item++;
	}
	for(; current_item < MAX_PLAYLIST_LENGTH;  current_item++)
	{
		PlayListList[current_item].Valid = false;
	}
	current_item = 0;
	return 0;
}

int PlayList::NextItemOnPlayList(tPlayListItem *Item)
{
	memcpy((void *) Item, (const void *) &(PlayListList[current_item].FileToPlay), sizeof(tPlayListItem));
	current_item++;
	return 0;
}

int PlayList::RewindPlayList()
{
   current_item = 0;
   return 0;
}

int PlayList::AddItemOnPlayList(tPlayListItem Item)
{

	memcpy(( void *) &(PlayListList[current_item].FileToPlay), (void *) &(Item.FileToPlay), sizeof(tPlayListItem));
	current_item++;

	return 0;
}

int PlayList::PrepareDumpFile(char * Buffer)
{
	int bytesWritten = 0;
	if (Buffer == NULL)
	{
		return bytesWritten;
	}
	else
	{
		for(int i=0; (i < MAX_PLAYLIST_LENGTH) && (i < current_item); i++)
		{
			bytesWritten += sprintf(&(Buffer[bytesWritten]), "%s %s %c %s %c %s %c %s %c %d\n",
													PlayListList[i].FileToPlay,
													PlayListList[i].OptionLabel[0],
													PlayListList[i].OptionCommand[0],
													PlayListList[i].OptionLabel[1],
													PlayListList[i].OptionCommand[1],
													PlayListList[i].OptionLabel[2],
													PlayListList[i].OptionCommand[2],
													PlayListList[i].OptionLabel[3],
													PlayListList[i].OptionCommand[3],
													PlayListList[i].CorrectOptionNumber);
		}
	
		return bytesWritten;
	}
}




