#pragma once

#include <stdio.h>

class LogResults
{
public:
	LogResults(void);
	~LogResults(void);
	int Start(char* Filename);
	int StoreResult(char* VideoFileName, char Selection, bool Correct, int TimeTaken);
	int Finish(void);
private:
	FILE *hFile;
};
