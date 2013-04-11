/*
   fsm_driver.cpp

   No arguments gives you the pretty colorized mode:

   ./fsm_driver.cpp

   The "--manual" argument causes the 'manual' function to run instead
   of running any of the unit test code:

   ./fsm_driver --manual

   The "--retrograde" argument causes the driver to run exacly as it
   does on the server:

   ./fsm_driver --retrograde

   Feel free to edit this file's manual() function to run your own
   testing. I have some stuff there to start with, you can use that or
   not, it is up to you.

 */
#include "fsm.hpp"

using namespace Thilenius;
using namespace std;

void manual() {
  // to run the manual tester just run
  // ./fsm_driver --manual

  cout << "Manual Program Begin" << endl;

  cout << "Manual Program End" << endl;
}

SUITE_BEGIN("Finite State Machines")

TEST_BEGIN("One")
{

}TEST_END

TEST_BEGIN("Two")
{

}TEST_END

TEST_BEGIN("Three")
{

}TEST_END

TEST_BEGIN("Four")
{

}TEST_END


SUITE_END

int main (int argc, char* argv[])
{	
  if (argc == 2 && argv[1] == string("--manual")) {
    manual();
  } else {
    UTFrameworkInit;
  }
}
