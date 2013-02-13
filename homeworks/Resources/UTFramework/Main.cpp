#include "UTFramework.h"
using namespace Thilenius;

SUITE_BEGIN("HelloTestingSuite!")

TEST_BEGIN("HelloSeg-Fault!")
{
	*((int*)0) = 4;
}TEST_END

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
// WINDOWS
	// Infinite loop catching is not supported in Windows.
#else

// LINUX
TEST_BEGIN("HelloInfinitLoop!")
{
	while ( true ) { }
}TEST_END

#endif

TEST_BEGIN("HelloNon-ShittyTest!")
{
	IsTrue("So", true, "");
	IsTrue("Many", true, "");
	IsTrue("Passes!!", true, "");
}TEST_END

SUITE_END


int main (int argc, char* argv[])
{	
	UTFrameworkInit;
}
