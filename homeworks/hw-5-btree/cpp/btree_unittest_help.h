#import "btree.h"
#import <vector>

/*
  The invariants structure has a bunch of booleans that (if true)
  indicate the invariant is held. False indicates a failure.
 */
struct invariants {
  // A node's keys are kept in ascending order, starting at index 0.
  bool ascending = false;

  // A node may have at most m children.
  bool not_fat = false;

  // Non-root nodes have at least round_up(m/2) - 1 keys
  bool not_starving = false;

  // If the root is not a leaf, it has at least two children.
  bool good_root = false;

  // All leaves are at the same level. Only need to check this if you
  // are running the invariant tests on the root of the entire tree.
  bool height_match = false;

  // child[i] holds keys that are less than key[i]. The final child
  // holds keys that are larger than the final key.
  bool child_key_order = false;
  
};

btree* init_node();

btree* build_empty();

btree* build_small();

btree* build_full_leaf_root();

btree* build_two_tier();

btree* build_full_two_tier();

btree* build_thin_three_tier();

btree* build_node(int size, int* keys);

void print_tree(btree* &root);

void check_invariants(invariants* &invars, btree* &node, bool is_root);

void check_leaf_height(btree* &node, vector<int> &depth, int current_depth);

bool check_height(btree* &node, int &result_height);

bool check_node_key_range(btree* &node, int low, int high, bool recurse);

bool any_false(invariants* &invars);

btree* load_tree_from_file(string &filename);

bool private_contains(btree* &node, int key);

