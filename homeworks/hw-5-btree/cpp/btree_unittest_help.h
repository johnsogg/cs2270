#import "btree.h"
#import <vector>

btree* init_node();

btree* build_empty();

btree* build_small();

btree* build_node(int size, int* keys);

void print_tree(btree* &root);
