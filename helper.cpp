#include "stdafx.h"
#include "helper.h"

bool FileExists(const char *filename)
{
	struct stat buf;
	if (stat(filename, &buf) != -1) return true;
	else return false;
}

void LoadSettings()
{
	const char *filename = "USR_SETTINGS";
	if (FileExists(filename))
	{

	}
	else
	{

	}
}

void CurrentTime(char *buff, int buffsize)
{
	time_t t;
	tm time_i;
	char now[32];

	time (&t);
	localtime_s (&time_i, &t);

	strftime(now, 32, "%y.%m.%d-%H:%M", &time_i);

	strcpy_s(buff, buffsize, now);
}
