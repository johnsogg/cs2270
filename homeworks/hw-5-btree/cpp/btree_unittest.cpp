#include "UTFramework.h"
#include "btree_unittest_help.h"

using namespace Thilenius;

vector<int> get_random_data(int how_many, int upper_bound);

bool passed_remove4 = false;

SUITE_BEGIN("BTree")

// TEST_BEGIN("SanityCheck")
// {
//   btree* root = build_empty();
//   IsTrue("Null Root?", root != NULL, "Root is NULL");
//   IsTrue("Leaf Root?", root->is_leaf, "Root is not a leaf");
//   IsTrue("Empty Root?", root->num_keys == 0, "Root has too many keys");

// }TEST_END

// TEST_BEGIN("SmallTree")
// {
//   btree* root = build_small();
//   int min_keys = BTREE_ORDER / 2;
//   IsTrue("2 keys", root->num_keys == 2, "Should have 2 keys");
//   for (int i=0; i <= 2; i++) {
//     IsTrue("Child not null", root->children[i] != NULL, "Child is null!");
//     IsTrue("Child is leaf", root->children[i]->is_leaf, "Child should be a leaf");
//     IsTrue("Child underfull", root->children[i]->num_keys >= min_keys, "Child is underfull");
//     IsTrue("Child overfull", root->children[i]->num_keys < BTREE_ORDER, "Child is overfull");
//   }
//   IsTrue("Look for known values", private_contains(root, 20), "Tree must contain 20");
//   IsTrue("Look for known values", private_contains(root, 2), "Tree must contain 2");
//   IsTrue("Look for known values", private_contains(root, 28), "Tree must contain 28");
//   IsTrue("Avoid wrong values", !private_contains(root, 30), "Tree must not contain 30");
//   IsTrue("Avoid wrong values", !private_contains(root, 14), "Tree must not contain 14");
// }TEST_END


// TEST_BEGIN("SmallTreeInvariants")
// {
//   btree* root = build_small();
//   invariants* invar = new invariants;
//   check_invariants(invar, root, true);
//   IsTrue("Ascending Keys", invar->ascending, "Keys are not in ascending order");
//   IsTrue("Not Fat", invar->not_fat, "Too many keys in node");
//   IsTrue("Not Starving", invar->not_starving, "Too few keys in non-root node");
//   IsTrue("Height Match", invar->height_match, "Leaves not all on same level");
//   IsTrue("Tree Key Order", invar->child_key_order, "Keys are not in sort order among all nodes");

// }TEST_END

TEST_BEGIN("Insert1")
{
  btree* root = build_empty();
  invariants* invar = new invariants;
  check_invariants(invar, root, true);
  IsTrue("Check Empty", !any_false(invar), "Default Empty Tree Breaks Invariant");
  insert(root, 10);
  check_invariants(invar, root, true);
  IsTrue("Check Invariants", !any_false(invar), "Inserting Breaks Invariant");
  IsTrue("Look for known values", private_contains(root, 10), "Tree must contain 10");  

  insert(root, 40);
  check_invariants(invar, root, true);
  IsTrue("Check Invariants", !any_false(invar), "Inserting Breaks Invariant");
  IsTrue("Look for known values", private_contains(root, 40), "Tree must contain 40");  

  insert(root, 30);
  check_invariants(invar, root, true);
  IsTrue("Check Invariants", !any_false(invar), "Inserting Breaks Invariant");
  IsTrue("Look for known values", private_contains(root, 30), "Tree must contain 30");  

  insert(root, 20);
  check_invariants(invar, root, true);
  IsTrue("Check Invariants", !any_false(invar), "Inserting Breaks Invariant");
  IsTrue("Look for known values", private_contains(root, 20), "Tree must contain 20");  
}TEST_END

TEST_BEGIN("Insert2")
{
  btree* root = build_full_leaf_root();
  invariants* invar = new invariants;
  check_invariants(invar, root, true);
  IsTrue("Check Empty", !any_false(invar), "Default Full Leaf Root Breaks Invariant");
  insert(root, 38);
  check_invariants(invar, root, true);
  IsTrue("Check Invariants", !any_false(invar), "Inserting Breaks Invariant");
  IsTrue("Look for known values", private_contains(root, 38), "Tree must contain just-added key");

  root = build_full_leaf_root();
  insert(root, 25);
  check_invariants(invar, root, true);
  IsTrue("Check Invariants", !any_false(invar), "Inserting Breaks Invariant");
  IsTrue("Look for known values", private_contains(root, 25), "Tree must contain just-added key");

  root = build_full_leaf_root();
  insert(root, 5);
  check_invariants(invar, root, true);
  IsTrue("Check Invariants", !any_false(invar), "Inserting Breaks Invariant");
  IsTrue("Look for known values", private_contains(root, 5), "Tree must contain just-added key");

  // IsTrue("AssertionName", true, "Error Message");
}TEST_END

TEST_BEGIN("Insert3")
{
  btree* root = build_two_tier();
  invariants* invar = new invariants;
  check_invariants(invar, root, true);
  IsTrue("Two-Tier Tree Sanity Check", !any_false(invar), "Initial Tree Incorrect");
  insert(root, 16);
  check_invariants(invar, root, true);
  IsTrue("Insertion Invariant Check", !any_false(invar), "Inserting Key Breaks Invariant(s)");
  bool ok = private_contains(root, 16);
  IsTrue("Contains Check", ok, "Tree does not contain key just inserted");
}TEST_END

TEST_BEGIN("Insert4")
{
  btree* root = build_full_two_tier();
  invariants* invar = new invariants;
  check_invariants(invar, root, true);
  IsTrue("Two-Tier Tree Sanity Check", !any_false(invar), "Initial Tree Incorrect");
  int height_before = 0;
  check_height(root, height_before);
  insert(root, 19);
  check_invariants(invar, root, true);
  IsTrue("Insertion Invariant Check", !any_false(invar), "Inserting Key Breaks Invariant(s)");
  IsTrue("Contains Check", private_contains(root, 19), "Tree does not contain key just inserted");
  int height_after = 0;
  check_height(root, height_before);
  IsTrue("Height Changed?", height_before + 1 == height_after, "Tree did not grow height by one.");
}TEST_END

TEST_BEGIN("Remove1")
{
  btree* root = build_full_leaf_root();
  invariants* invar = new invariants;
  check_invariants(invar, root, true);
  IsTrue("Check Empty", !any_false(invar), "Default Full Leaf Root Breaks Invariant");

  remove(root, 20);
  check_invariants(invar, root, true);
  IsTrue("Invariant Check", !any_false(invar), "Invariants Broken");
  bool ok = !private_contains(root, 20);
  IsTrue("Contains Check", ok, "Tree still contains key that was just removed");

  remove(root, 10);
  check_invariants(invar, root, true);
  IsTrue("Invariant Check", !any_false(invar), "Invariants Broken");
  ok = !private_contains(root, 10);
  IsTrue("Contains Check", ok, "Tree still contains key that was just removed");

  remove(root, 40);
  check_invariants(invar, root, true);
  IsTrue("Invariant Check", !any_false(invar), "Invariants Broken");
  ok = !private_contains(root, 40);
  IsTrue("Contains Check", ok, "Tree still contains key that was just removed");

  remove(root, 30);
  check_invariants(invar, root, true);
  IsTrue("Invariant Check", !any_false(invar), "Invariants Broken");
  ok = !private_contains(root, 30);
  IsTrue("Contains Check", ok, "Tree still contains key that was just removed");


  // IsTrue("AssertionName", true, "Error Message");
}TEST_END

TEST_BEGIN("Remove2")
{
  btree* root = build_two_tier();
  invariants* invar = new invariants;
  check_invariants(invar, root, true);
  IsTrue("Two-Tier Tree Sanity Check", !any_false(invar), "Initial Tree Incorrect");
  remove(root, 17);
  check_invariants(invar, root, true);
  IsTrue("Insertion Invariant Check", !any_false(invar), "Inserting Key Breaks Invariant(s)");
  bool ok = !private_contains(root, 17);
  IsTrue("Contains Check", ok, "Tree still contains key that was just removed");
}TEST_END


TEST_BEGIN("Remove3")
{
  btree* root = build_full_two_tier();
  invariants* invar = new invariants;
  check_invariants(invar, root, true);
  IsTrue("Two-Tier Tree Sanity Check", !any_false(invar), "Initial Tree Incorrect");
  int height_before = 0;
  check_height(root, height_before);
  remove(root, 6);
  check_invariants(invar, root, true);
  IsTrue("Invariant Check", !any_false(invar), "Remove Breaks An Invariant");
  bool ok = !private_contains(root, 6);
  IsTrue("Contains Check", ok, "Tree still contains key that was just removed");
  int height_after = 0;
  check_height(root, height_after);
  IsTrue("Height Same?", height_before == height_after , "Height should not have changed");
}TEST_END


TEST_BEGIN("Remove4")
{
  btree* root = build_thin_three_tier();
  invariants* invar = new invariants;
  check_invariants(invar, root, true);
  IsTrue("Three-Tier Tree Sanity Check", !any_false(invar), "Initial Tree Incorrect");
  int height_before = 0;
  check_height(root, height_before);
  remove(root, 5);
  check_invariants(invar, root, true);
  IsTrue("Invariant Check", !any_false(invar), "Remove Breaks An Invariant");
  passed_remove4 = !any_false(invar);
  bool ok = !private_contains(root, 5);
  IsTrue("Contains Check", ok, "Tree still contains key that was just removed");
  passed_remove4 = passed_remove4 && ok;
  int height_after = 0;
  check_height(root, height_after);
  IsTrue("Height Same?", height_before == height_after - 1, "Height should reduce by one");
  passed_remove4 = passed_remove4 && height_before == height_after - 1;
  // IsTrue("AssertionName", true, "Error Message");
}TEST_END


TEST_BEGIN("BulkRandom")
{
  if (passed_remove4) {
    vector<int> data = get_random_data(400, 1000);
    btree* root = build_empty();
    invariants* invar = new invariants;
    for (size_t i=0; i < data.size(); i++) {
      insert(root, data[i]);
      if (i % 10 == 0) {
	check_invariants(invar, root, true);
	IsTrue("Invariant Check", !any_false(invar), "Invariant Broken During Bulk Insert");
	bool ok = contains(root, data[i]);
	IsTrue("Check Inserted Key", ok, "Inserted key not present");
	if (any_false(invar) || !ok) {
	  break;
	}
      }
    }
    for (size_t i=0; i < data.size(); i++) {
      remove(root, data[i]);
      if (i % 10 == 0) {
	check_invariants(invar, root, true);
	IsTrue("Invariant Check", !any_false(invar), "Invariant Broken During Bulk Remove");
	bool ok = !contains(root, data[i]);
	IsTrue("Check Removed Key", ok, "Removed key is present");
	if (any_false(invar) || !ok) {
	  break;
	}
      }
    }
  } else {
    IsTrue("Need To Pass Remove4", false, "Pass Remove4 To Unlock The Secret Level");
  }

}TEST_END

SUITE_END

vector<int> get_random_data(int how_many, int upper_bound) {
  vector<int> numbers;
  for (int i=0; i < how_many; i++) {
    int r = rand() % upper_bound;
    numbers.push_back(r);
  }
  return numbers;
}


int main (int argc, char* argv[])
{	
	UTFrameworkInit;
	build_full_two_tier();
}
