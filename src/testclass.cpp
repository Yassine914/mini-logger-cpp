#include "logger.h"


void TestLogger()
{
    LOGINIT_COUT();

    Log(LOG_INFO) << "hello";
}