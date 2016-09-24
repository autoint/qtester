#include ".\logresults.h"
#include "string.h"

LogResults::LogResults(void)
{
	hFile = NULL;
}

LogResults::~LogResults(void)
{
}

int LogResults::Start(char* Filename)
{
	if((Filename != NULL) || (strlen(Filename) != 0))
	fopen_s(&hFile, Filename, "w");
	if (hFile == NULL)
	{
		while(1);
	}
	return 0;
}

int LogResults::StoreResult(char* VideoFileName, char Selection, bool Correct, int TimeTaken)
{
	if (hFile == NULL)
	{
		while(1);
	}
	else
	{
		fprintf(hFile, "%s , %c , %d, ",  VideoFileName, Selection, TimeTaken);
		if (Correct)
		{
			fprintf(hFile, "PASS\n");
		}
		else
		{
			fprintf(hFile, "FAIL\n");
		}
		fflush(hFile);
	}

	return 0;
}

int LogResults::Finish(void)
{
	if (hFile == NULL)
	{
		while(1);
	}
	else
	{
		fclose(hFile);
	}
	return 0;
}
