Homework 1: Linked Lists
==========

__Due Friday Jan 25 at 6pm__

_Late assignments are capped at 5 points_

This homework assignment gives you a chance to build a useful,
real-world data structure called a Linked List.

Linked Lists are discussed in the Shaffer text. However, the examples
there are given using advanced object-oriented C++ features. So the
text is accurate and helpful (let me know if it isn't!), the code is
probably a bit cryptic.

[Linked Lists Basics](http://cslibrary.stanford.edu/103/LinkedListBasics.pdf)
from Stanford is remarkably legible, and it helpfully uses a similar
simplified coding technique that we will use in this assignment. The
Stanford examples are actually in pure C, not C++.

One notable difference: in C you might build a new node like this:

	struct node* new_node = malloc(sizeof(struct node));
	
In C++ the way we will do it is a bit different:

	node* new_node = new node;

I'm also adding my slide tutorials on pointers and linked lists to
this homework directory. I showed them in class when we covered linked
lists and pointers. Consult them if you need inspiration.

Instructions
--------

Download the source files in the 'cpp' directory for homework 1.
Implement the following functions in `linked_list.cpp`. Use the
provided Makefile to build your program (cd to where your source code
lives, where the Makefile is, and type `make`). _Later this afternoon
I will create a simple testing program that should help out
substantially._

The point value for correctly implement each is given.

	node* init_node(int data); // 1 point
	
	std::string report(node* root); // 2 points
	
	void append_data(node* head, int data); // 1 point
	
	void append(node* head, node* new_node); // 2 points

	void insert_data(node* head, int offset, int data); // 1 point

	void insert(node* head, int offset, node* new_node); // 3 points

	void remove(node* parent, int offset); // 3 points

	int size(node* head); // 1 point

	bool contains(node* head, int data); // 1 point

You must do this assignment in C++.

For extra credit, you can do this in Python or Java. __Note: These
will be released by Tuesday. Sorry for the delay, I will get ahead of
the game as soon as possible.__

Turning In Your Homework
--------

We will use a new automated grading system called RetroGrade. I am
spending the weekend getting this to run on the department's
network. Watch this space for further instructions. I will push back
the due date if I can't get it working by Tuesday.
