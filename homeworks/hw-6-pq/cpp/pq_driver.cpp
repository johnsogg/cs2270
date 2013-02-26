//
// pq_driver.cpp
//
// This is an empty unit test file that you can implement (or not) to
// create unit tests for your code.
//
// You'll likely want one for insert, remove, and peek. Try to think
// about how your queue could break, and write tests that help you
// test your deepest priority-queue-related fears.
//
// The test code will appear on RetroGrade late in the game.

#include "UTFramework.h"
#include "pq.h"

using namespace Thilenius;

SUITE_BEGIN("Priority Queue")

TEST_BEGIN("SanityCheck")
{
  IsTrue("Sane?", true, "OK I'm insane");
}TEST_END

SUITE_END

int main (int argc, char* argv[])
{	
  UTFrameworkInit;
}
