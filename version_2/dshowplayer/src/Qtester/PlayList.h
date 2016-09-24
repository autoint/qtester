#pragma once
#include "QTesterConstants.h"
#include "rapidxml.hpp"

class PlayList
{

private:
	typedef struct
	{
		char FileToPlay[QTesterConstants::MAX_PATH_LENGTH];
		char  OptionLabel[QTesterConstants::MAX_OPTION_POSSIBLE][QTesterConstants::MAX_LABEL_LENGTH];
		char  OptionCommand[QTesterConstants::MAX_OPTION_POSSIBLE];
		char  CorrectOptionNumber;

	} tPlayListItem;
	tPlayListItem PlayListList[QTesterConstants::MAX_PLAYLIST_LENGTH];
	int current_item;
	

public:

	PlayList();
	~PlayList();

	int ReadPlayList(String FileName);
	int NextItemOnPlayList(tPlayListItem *FileName);
	bool CreatePlaylist(String FileName);


	


};

