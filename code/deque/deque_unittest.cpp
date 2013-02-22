/*

  deque_unittest.cpp

*/

#include <cstring>
#include <cstdlib>
#include "deque.h"
#include "UTFramework.h"

using namespace Thilenius;
using namespace std;

extern int RETROGRADE_MODE;

/* begin a suite. This is a collection of tests. */

SUITE_BEGIN("Deque")     

/* now define tests with the same form as the sanity check. */

TEST_BEGIN("Sanity Check") {
  IsTrue("Sane?",        // label in output
	 false,           // a truth test
	 "I'm insane!"); // error message when needed
}TEST_END

 /* end the suite, since all of this was a macro definition. */

SUITE_END

 /* the below is just a main function to get the unit test started. */
void printUsage(char call[]) {
  cout << " Usage: " << call << " [--retrograde]" << endl;
}

int main (int argc, char* argv[]) {
  if (argc == 2 && strcmp(argv[1], "--retrograde") == 0) RETROGRADE_MODE = 1;
  else if (argc != 1) { 
    printUsage(argv[0]);
    return -1;
  }
  UTFrameworkInit;
}
