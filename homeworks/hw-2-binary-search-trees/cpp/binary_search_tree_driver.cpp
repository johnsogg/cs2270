/*

  binary_search_tree_driver.cpp



             .__.       .============================.
            .(\\//).  .-[ A Gift: Pre-written Driver ]
           .(\\()//)./  `============================'
       .----(\)\/(/)----.
       |     ///\\\     |
       |    ///||\\\    |    N O T E:
       |   //`||||`\\   |
       |      ||||      |  This is the last time I will give you
       |      ||||      |  such comprehensive testing code. Next
       |      ||||      |  assignment this will be substantially
       |      ||||      |  shorter and incomplete. On purpose.
       |      ||||      |  Because I am mean. And also because
       |      ||||      |  writing your own testing code is an
       '------====------'  absolutely imparative skill.
                         
   The main() function is at the end. A useful strategy for competing
   this assignment might be to comment out the calls to run the things
   that you haven't worked on yet.

   Take careful note of how this driver is structured. You will be
   responsible for writing something like this in the future. Once you
   have a real job writing software for a living, you will most likely
   be expected to write test code as a matter of course.

   NOTE that there are lots of commented out cout statements. If you
   are having trouble figuring out why something is failing,
   un-comment them.

*/
#include <iostream>
#include <vector>
#include "binary_search_tree.h"

using namespace std;

void print_vec(char* msg, vector<int>& vec) {
  cout << msg << " ";
  if (vec.size() == 0) {
    cout << "<empty>";
  } else {
    for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++) {
      cout << *it << " ";
    }
  }
  cout << endl;
}

void do_inorder_walk(bt_node* n, vector<int>& inorder) {
  if (n != NULL) {
    //    cout << "inorder_walk on node " << n->data << " going left..." << endl;
    do_inorder_walk(n->left, inorder);
    //    cout << "visiting node " << n->data << endl;
    inorder.push_back(n->data);
    //    cout << "inorder_walk on node " << n->data << " going right..." << endl;
    do_inorder_walk(n->right, inorder);
  } else {
    //    cout << "(no child)" << endl;
  }
}

vector<int> begin_inorder_walk(bt_node* top) {
  //  cout << "Begin an inorder walk!" << endl;
  vector<int> inorder;
  if (top != NULL) {
    do_inorder_walk(top, inorder);
  }
  return inorder;
}

void compare_vectors(vector<int>& desired, vector<int>& actual) {
  //  cout << "Should be same: " << endl;
  //  print_vec("   Actual:", actual);
  //  print_vec("  Desired:", desired);
  if (desired != actual) {
    cout << "Vectors are not the same!" << endl;
    print_vec("   Actual:", actual);
    print_vec("  Desired:", desired);
  }
}

void test_init_node() {
  cout << "Test Init Node BEGIN" << endl;
  bt_node* four = init_node(4);
  if (four == NULL || four->data != 4) {
    cout << "Should be 4: " << four->data << endl;
  }
  if (four->left != NULL) {
    cout << "Should be NULL (0): " << four->left << endl;
  }
  if (four->right != NULL) {  
    cout << "Should be NULL (0): " << four->right << endl;
  }
  cout << "Test Init Node END" << endl;
}

void test_insert() {
  cout << "Test Insert BEGIN" << endl;
  bt_node* top = NULL; // start with an empty tree
  bt_node* four = init_node(4);
  vector<int> desired;

  insert(&top, four); // insert four
  desired.push_back(4);
  vector<int> result = begin_inorder_walk(top);
  compare_vectors(desired, result);

  insert_data(&top, 5);
  desired.push_back(5);
  result = begin_inorder_walk(top);
  compare_vectors(desired, result);

  insert_data(&top, 1);
  desired.insert(desired.begin(), 1);
  result = begin_inorder_walk(top);
  compare_vectors(desired, result);  

  insert_data(&top, 2);
  desired.insert(desired.begin()+1, 2);
  result = begin_inorder_walk(top);
  compare_vectors(desired, result);  

  insert_data(&top, 4);
  desired.insert(desired.begin()+2, 4);
  result = begin_inorder_walk(top);
  compare_vectors(desired, result);  

  cout << "Test Insert END" << endl;
}

void test_contains_and_size() {
  cout << "Test Contains and Size BEGIN" << endl;
  bt_node* top = NULL;
  if (contains(top, 0)) {
    cout << "Error: empty tree should not contain() anything." << endl;
  }
  if (size(top) != 0) {
    cout << "Error: empty tree should have zero size." << endl;
  }
  // add a bunch of numbers: -3, 1, 2, 3, 5, 15
  insert_data(&top, 5);
  if (size(top) != 1) {
    cout << "Tree with one element should have size of 1." << endl;
  }
  insert_data(&top, 1);
  insert_data(&top, 3);
  insert_data(&top, -3);
  insert_data(&top, 2);
  insert_data(&top, 15);
  insert_data(&top, 5);
  if (size(top) != 7) {
    cout << "Tree with 7 elements should have size of 7." << endl;
  }


  // ensure it contains all of the following
  if (contains(top, -3) && 
      contains(top, 1) && 
      contains(top, 2) && 
      contains(top, 3) && 
      contains(top, 5) && 
      contains(top, 15)) {
    // ok.
  } else {
    cout << "Error: tree reports that it does not contain " 
	 << "something that it should." << endl;
  }

  // ensure it contains none of the following
  if (contains(top, 0) || contains(top, 4)) {
    cout << "Error: tree reports that it contains " 
	 << "something that it should not." << endl;
  }
  
  cout << "Test Contains and Size END" << endl;  
}

void test_get_node() {
  cout << "Test Get Node BEGIN" << endl;  
  bt_node* top = NULL;
  if (get_node(top, 0) != NULL) {
    cout << "get_node(NULL) should return NULL" << endl;
  }
  top = init_node(4);
  top->left = init_node(1);
  top->left->right = init_node(2);
  top->right = init_node(5);
  top->right->left = init_node(4);
  if (get_node(top, 1) != top->left) {
    cout << "get_node(top, 1) should return top->left" << endl;
  }
  if (get_node(top, 2) != top->left->right) {
    cout << "get_node(top, 2) should return top->left->right" << endl;
  }
  bt_node* four = get_node(top, 4);
  if ((four == top) || (four == top->right->left)) {
    // ok
  } else {
    cout << "get_node(top, 4) should return top OR top->right->left" << endl;
  }
  if (get_node(top, 5) != top->right) {
    cout << "get_node(top, 5) should return top->right" << endl;
  }

  cout << "Test Get Node  END" << endl;  
}

void test_remove() {
  cout << "Test Remove BEGIN" << endl;
  bt_node* top = NULL;
  remove(&top, 8); // should have no effect. this is here to detect segfaults
  insert_data(&top, 7);
  insert_data(&top, 5);
  insert_data(&top, 10);
  insert_data(&top, 4);
  insert_data(&top, 6);
  insert_data(&top, 9);
  insert_data(&top, 11);
  
  vector<int> desired;
  desired.push_back(4);
  desired.push_back(5);
  desired.push_back(6);
  desired.push_back(7);
  desired.push_back(9);
  desired.push_back(10);
  desired.push_back(11);

  //  cout << "Size at start of remove process: " << size(top) << endl;
  vector<int> contents = begin_inorder_walk(top);
  compare_vectors(desired, contents);
  //  print_vec("Contents: ", contents);
  remove(&top, 11); // zero children
  desired.erase(desired.begin() + 6);
  contents = begin_inorder_walk(top);
  compare_vectors(desired, contents);

  contents = begin_inorder_walk(top);
  //  cout << "Size after removing 11: " << size(top) << endl;  
  //  print_vec("Contents: ", contents);
  remove(&top, 4); // again, but on the left side.
  desired.erase(desired.begin());
  contents = begin_inorder_walk(top);
  compare_vectors(desired, contents);

  // cout << "Size after removing 4: " << size(top) << endl;  
  // print_vec("Contents: ", contents);
  remove(&top, 5); // one child (right)
  desired.erase(desired.begin());
  contents = begin_inorder_walk(top);
  compare_vectors(desired, contents);

  //cout << "Size after removing 5: " << size(top) << endl;  
  //  print_vec("Contents: ", contents);
  remove(&top, 6); // no children, but should not have been orphaned after the 5
  desired.erase(desired.begin());
  contents = begin_inorder_walk(top);
  compare_vectors(desired, contents);
  //  cout << "Size after removing 6: " << size(top) << endl;  
  //  print_vec("Contents: ", contents);

  //  cout << endl << "Resetting tree..." << endl << endl;
  // re-build tree so we can test removing inside parts
  top = NULL;
  insert_data(&top, 7);
  insert_data(&top, 5);
  insert_data(&top, 10);
  insert_data(&top, 4);
  insert_data(&top, 6);
  insert_data(&top, 9);
  insert_data(&top, 11);
  desired.clear();
  desired.push_back(4);
  desired.push_back(5);
  desired.push_back(6);
  desired.push_back(7);
  desired.push_back(9);
  desired.push_back(10);
  desired.push_back(11);

  //  contents = begin_inorder_walk(top);
  //  print_vec("Initial Contents: ", contents);

  remove(&top, 7); // remove top of tree
  contents = begin_inorder_walk(top);
  desired.erase(desired.begin() + 3);
  compare_vectors(desired, contents);

  // cout << "Size after removing 7: " << size(top) << endl;  
  //  print_vec("Contents: ", contents);

  remove(&top, 10); // remove top of tree
  contents = begin_inorder_walk(top);
  desired.erase(desired.begin() + 4);
  compare_vectors(desired, contents);

  //  cout << "Size after removing 10: " << size(top) << endl;  
  //  print_vec("Contents: ", contents);
  cout << "Test Remove END" << endl;

}

void test_to_array() {
  cout << "Test ToArray BEGIN" << endl;

  bt_node* top = NULL;
  insert_data(&top, 7);
  insert_data(&top, 5);
  insert_data(&top, 10);
  insert_data(&top, 4);
  insert_data(&top, 6);
  insert_data(&top, 9);
  insert_data(&top, 11);
  int expected[] = { 4, 5, 6, 7, 9, 10, 11 };
  int arr_size = size(top);
  int arr[arr_size];
  to_array(top, arr);

  //  cout << "Got array: " << arr << " of size: " << arr_size << endl;
  //  for (int i=0; i < arr_size; i++) {
  //    cout << "At elm " << i << endl;
  //    cout << "element " << i << ": " << arr[i] << endl;
  //  }

  if (arr_size != 7) {
    cout << "Return array should be 7 long, but it is " << arr_size << endl;
  } else {
    // ensure they have the same values.
    for (int i=0; i < arr_size; i++) {
      if (arr[i] != expected[i]) {
	cout << "At element " << i << " got value " << arr[i] << " but expected "
	     << expected[i] << endl;
      }
    }
  }

  cout << "Test ToArray END" << endl;
}
int main () {
  cout << "Binary Search Tree Driver BEGIN" << endl;

  test_init_node();
  test_insert();
  test_contains_and_size();
  test_get_node();
  test_remove();
  test_to_array();

  cout << "Binary Search Tree Driver END" << endl;
}
