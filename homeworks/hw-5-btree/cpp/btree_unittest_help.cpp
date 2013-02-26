//
// btree_unittest_help.cpp
//
// This is the start of a bunch of helper functions. I'm giving it to
// you so you can use it as a starting point for your own purposes (or
// not, it is up to you).

#include "btree_unittest_help.h"
#include "btree.h"
#include <vector>
#include <sstream>
#include <string>

using namespace std;

btree* init_node() {
  btree* ret = new btree;
  ret->num_keys = 0;
  ret->is_leaf = true;
  for (int i=0; i <= BTREE_ORDER; i++) {
    ret->children[i] = NULL;
  }
  return ret;
}

btree* build_empty() {
  return init_node();
}

btree* build_small() {
  int vals[] = { 10, 20 };
  // does anybody know a better way to pass in the int[] so I don't
  // have to do this on two lines? let me know
  btree* root = build_node(2, vals);
  // now we need three children
  int vals2[] = { 2, 8 };
  btree* left = build_node(2, vals2);
  int vals3[] = { 13, 17 };
  btree* mid =  build_node(2, vals3);
  int vals4[] = { 24, 28 };
  btree* right = build_node(2, vals4);
  root->is_leaf = false;
  root->children[0] = left;
  root->children[1] = mid;
  root->children[2] = right;
  return root;
}

btree* build_node(int size, int* keys) {
  btree* node = init_node();
  node->num_keys = size;
  for (int i=0; i < node->num_keys; i++) {
    node->keys[i] = keys[i];
  }
  return node;
}

string get_id_for_dot(btree* &node) {
  stringstream ss;
  ss << node; // address in memory
  string as_addr = ss.str();
  as_addr.replace(0, 2, "BT_");
  return as_addr;
}

string get_label_for_dot(btree* &node) {
  stringstream ss;
  for (int i=0; i < node->num_keys; i++) {
    ss << "" << node->keys[i];
    if (i+1 < node->num_keys) {
      ss << " ";
    }
  }
  return ss.str();
}

void print_dot_label(btree* &node) {
  cout << "    " << get_id_for_dot(node) 
       << " [label=\"" << get_label_for_dot(node) << "\"];" << endl;
}

void print_graphviz_dotfile(btree* &node, int depth) {
  string spaces = "    ";
  if (depth == 0) {
    print_dot_label(node);
  }
  int idx = 0;
  string my_id = get_id_for_dot(node);
  for ( ; idx < node->num_keys; idx++) {
    if (!node->is_leaf) { // don't recurse if this is a leaf.
      print_dot_label(node->children[idx]);
      cout << spaces << my_id << " -- " << get_id_for_dot(node->children[idx]) << ";" << endl;
      print_graphviz_dotfile(node->children[idx], depth + 1);
    }
  }
  // there is always one leftover child, assuming it is not a leaf.
  if (!node->is_leaf) {
    print_dot_label(node->children[idx]);
    cout << spaces << my_id << " -- " << get_id_for_dot(node->children[idx]) << ";" << endl;
    print_graphviz_dotfile(node->children[idx], depth + 1);    
  }
}


void print_tree(btree* &root) {
  cout << "graph btree {" << endl;
  int depth = 0;
  print_graphviz_dotfile(root, depth);
  cout << "}" << endl;
}
