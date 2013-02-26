#include "UTFramework.h"
#include "btree_unittest_help.h"

using namespace Thilenius;

SUITE_BEGIN("BTree")

TEST_BEGIN("SanityCheck")
{
  btree* root = build_empty();
  IsTrue("Null Root?", root != NULL, "Root is NULL");
  IsTrue("Leaf Root?", root->is_leaf, "Root is not a leaf");
  IsTrue("Empty Root?", root->num_keys == 0, "Root has too many keys");

}TEST_END

TEST_BEGIN("SmallTree")
{
  btree* root = build_small();
  int min_keys = BTREE_ORDER / 2;
  IsTrue("2 keys", root->num_keys == 2, "Should have 2 keys");
  for (int i=0; i <= 2; i++) {
    IsTrue("Child not null", root->children[i] != NULL, "Child is null!");
    IsTrue("Child is leaf", root->children[i]->is_leaf, "Child should be a leaf");
    IsTrue("Child underfull", root->children[i]->num_keys >= min_keys, "Child is underfull");
    IsTrue("Child overfull", root->children[i]->num_keys < BTREE_ORDER, "Child is overfull");
  }
  print_tree(root);
}TEST_END


 // Dear CS 2270, Go ahead and make more unit tests that check your
 // code against the invariants discussed in class. These are
 // summarized in homework 4's directory. There's one on invariants,
 // and another on B-Trees in general.

// TEST_BEGIN("")
// {
//   // IsTrue("AssertionName", true, "Error Message");
// }TEST_END

SUITE_END

int main (int argc, char* argv[])
{	
	UTFrameworkInit;
}
