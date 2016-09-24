#pragma once
#include <windows.h>
#include <time.h>

class LocalTimer
{
public:
	LocalTimer(void);
	~LocalTimer(void);
	int Start(void);
	int Stop(void);
	int TimeTaken(void);

private:
	DWORD  lpPerformanceCount_start;
	DWORD lpPerformanceCount_end;
	LARGE_INTEGER lpFrequency;
};
