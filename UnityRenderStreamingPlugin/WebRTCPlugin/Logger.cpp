﻿#include "pch.h"
#include <cstdarg>
#include "WebRTCPlugin.h"

void LogPrint(const char* fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
#ifdef _WIN32
    char buf[2048];
    vsprintf_s(buf, fmt, vl);
    ::debugLog(buf);
#else
    vprintf(fmt, vl);
#endif
    va_end(vl);
}
void checkf(bool result, const char* msg)
{
    if (!result)
    {
        LogPrint(msg);
    }
}
