/*
 * STUDENTS: I'm not done yet. This will change. I need to implement
 * it myself first.
 */

#include <vector>
#include <string>
#include <queue>
#ifndef huffman_h
#define huffman_h

using namespace std;

struct freq_info {
  char symbol;
  float freq;
  freq_info* left;
  freq_info* right;
  bool is_leaf;
  bool operator() (freq_info* a, freq_info* b) {
    return a->freq > b->freq;
  }
};

/*
 * I got sick of typing all this template parameterization stuff. So I
 * typedef'ed the priority queue type to simply 'tree_queue'.
 */
typedef priority_queue<freq_info*, vector<freq_info*>, freq_info> tree_queue;

freq_info* init_freq_info(char symbol, float freq);

void add_freq(char c, map<char, int> &data);

tree_queue read_corpus(string filename);

void debug_queue(tree_queue queue);

#endif
