#include "Log.h"
#include <stdio.h>
#include <cstdarg>

namespace rdcboost
{
	void Assert(bool b)
	{
		if (!b)
		{
			LogError("Assertion failed.");
			throw b;
		}
	}

	void LogError(const char* logFmt, ...)
	{
		va_list vl;
		va_start(vl, logFmt);
		vfprintf(stderr, logFmt, vl);
		va_end(vl);
	}

	void LogWarn(const char* logFmt, ...)
	{
		va_list vl;
		va_start(vl, logFmt);
		vprintf(logFmt, vl);
		va_end(vl);
	}

}

