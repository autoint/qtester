#include "PlayList.h"




PlayList::PlayList()
{
	char* text = nullptr;
	using namespace rapidxml;
	xml_document<> doc;    // character type defaults to char
	doc.parse<0>(text);    // 0 means default parse flags
}

PlayList::PlayList(String FileName)
{
	
	rapidxml::xml_document<> doc;    // character type defaults to char
	doc.parse<0>(text);    // 0 means default parse flags
}


PlayList::~PlayList()
{
}


int ReadPlayList(String FileName)
{
	return 0;
}

int NextItemOnPlayList(tPlayListItem *FileName)
{
	return 0;
}

bool CreatePlaylist(String FileName)
{
	return false;
}
