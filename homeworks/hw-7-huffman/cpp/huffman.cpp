#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include "huffman.h"

using namespace std;

void add_freq(char c, map<char, int> &data) {
  if (data[c] == 0) {
    data[c] = 1;
  } else {
    data[c] = data[c] + 1;
  }
}


int main () {
  /*  1. Create a priority queue of one-node trees using some big text
      file. This gives you a priority queue containing freq_info
      objects. These are meant to be used as nodes in a tree. At the
      moment, they are all disconnected, so you have a forest of tiny
      one-node seedlings. 
  */
  tree_queue queue = read_corpus("pkd.txt");
   
  /*  2. Now do something like the following:

      while priority queue has more than one item: 

        Pop top two items, A and B. They are lowest frequency nodes.
        Create non-leaf node C who points to children A and B. C's
        frequency is the sum of A and B's frequency.  Insert C back
        into the priority queue.
   */

  /*  3. We are left with a priority queue with a single node. This is
      the root of a huffman tree. The leafs all contain symbols. The
      path from root to a leaf is the huffman encoding for that leaf's
      symbol. Every time a left child is followed, that corresponds to
      a zero bit; right children are one bits.

      Now traverse the tree and create a bitstring for each leaf. If
      the path from the root to the leaf happens to be Left Left Right
      Left, the bitstring for that leaf is 0010. Store these
      bitstrings in a datastructure where you can search using a
      character and retrieve the bitstring. A Map would work.
   */

  /*  4. Now that we have a Map of symbols to bitstrings, we can use
      it to encode text data. I'll give little sentences to
      encode. Your functions have to output strings (yes, strings)
      that use '.' as 0 and '^' as 1. Something like this:

      ...^..^^.^..^.^^...^.^..^..^.^^^...^.....^^...^^^..^.^.^..^.^.^.^.^.

      We're using strings rather than actual bits so (a) we can read
      and debug it, and (b) so we don't have to deal with chopping up
      individual bytes in memory. That's not really the point of the
      exercise.

   */

  /*  5.  After encoding some strings into your huffman coded 'bit'
      string, I'll use your decode function to get back the
      original. The way you do this is to read the input character by
      character, starting from the root of your huffman tree. When you
      see an asterisk, you move left; a plus, move right. When you
      reach a leaf node, you have found the coded character. Record
      that character. Move back to the root and continue reading the
      input string until it is complete. The sequence you read should
      be the original message.

   */
}

void debug_queue(tree_queue queue) {
  while (!queue.empty()) {
    freq_info* info = queue.top();
    cout << info->symbol << " == " << info->freq << endl;
    queue.pop();
  }
}

freq_info* init_freq_info(char symbol, float freq) {
  freq_info* ret = new freq_info;
  ret->symbol = symbol;
  ret->freq = freq;
  ret->left = NULL;
  ret->right = NULL;
  ret->is_leaf = true;
  return ret;
}

tree_queue read_corpus(string filename) {
  ifstream myfile;
  string line;
  myfile.open(filename.c_str());
  map<char, int> freq;
  if (myfile.is_open()) {
    while (myfile.good()) {
      getline(myfile, line);
      for (unsigned i=0; i < line.length(); i++) {
	add_freq(line[i], freq);
      }
      add_freq('\n', freq);
    }
    myfile.close();

    int largest = 0;
    int sum = 0;
    int num_chars = 0;
    for (map<char, int>::iterator it = freq.begin();
	 it != freq.end(); it++) {
      largest = max(largest, it->second);
      sum = sum + it->second;
    }
    cout << "Number of unique characters: " << freq.size() << endl;
    cout << "Number of character instances: " << sum << endl;
    cout << "Most frequent char was seen " << largest << " times." << endl;

    // now we know the total number so we can calculate frequency data.
    float fsum = (float) sum;
    tree_queue queue;
    for (map<char, int>::iterator it = freq.begin();
	 it != freq.end(); it++) {
      freq_info* info = init_freq_info(it->first, it->second);

      info->symbol = it->first;
      info->freq = (float) it->second / fsum;
      queue.push(info);
    }
    cout << "Read file: " << filename << endl;
  } else {
    cout << "WARNING: could not read file: " << filename << endl;
  }

}
