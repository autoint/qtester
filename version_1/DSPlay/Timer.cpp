#include ".\timer.h"
#include <time.h>

LocalTimer::LocalTimer(void)
{
	
}

LocalTimer::~LocalTimer(void)
{
}

int LocalTimer::Start(void)
{
	if(timeBeginPeriod((UINT) 1) == TIMERR_NOERROR)
	{
		lpPerformanceCount_start = timeGetTime();
	}
	return 0;
}

int LocalTimer::Stop(void)
{
	lpPerformanceCount_end =  timeGetTime();
	timeEndPeriod((UINT) 1);
	return 0;
}

int LocalTimer::TimeTaken(void)
{
	return (int) (lpPerformanceCount_end - lpPerformanceCount_start);
}
