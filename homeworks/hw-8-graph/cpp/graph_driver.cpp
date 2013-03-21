/*
   graph_driver.cpp

   This is the driver for the graph assignment on breadth-first and
   depth-first search. There are three ways to run this.

   No arguments gives you the pretty colorized mode:

   ./graph_driver.cpp

   The "--manual" argument causes the 'manual' function to run instead
   of running any of the unit test code:

   ./graph_driver --manual

   The "--retrograde" argument causes the driver to run exacly as it
   does on the server:

   ./graph_driver --retrograde

   Feel free to edit this file's manual() function to run your own
   testing. I have some stuff there to start with, you can use that or
   not, it is up to you.

 */
#include "UTFramework.h"
#include "Graph.hpp"

using namespace Thilenius;
using namespace std;

void manual() {
  cout << "Graph Program Begin" << endl;
  Graph graph;
  Node a("a");
  Node b("b");
  cout << "Nodes a and b: " << a << " " << b << endl;
  graph.addNode(a);
  graph.addNode(b);
  Edge ab(a, b);
  cout << "Edge ab: " << ab << endl;
  graph.addEdge(ab);
  cout << "Whole graph: " << endl << graph << endl;
  cout << "Removing edge." << endl;
  graph.removeEdge(ab);
  cout << "Whole graph: " << endl << graph << endl;
  cout << "Removing node a" << endl;
  graph.removeNode(a);
  cout << "Whole graph: " << endl << graph << endl;
  cout << "Removing node b" << endl;
  graph.removeNode(b);
  cout << "Whole graph: " << endl << graph << endl;

  Node c("c");
  Node d("d");
  Node e("e");
  Node f("f");
  Node g("g");

  Edge ac(a, c);
  Edge bc(b, c);
  Edge ae(a, e);
  Edge ce(c, e);
  Edge cd(c, d);
  Edge dg(d, g);
  Edge eg(e, g);
  Edge df(d, f);
  Edge fb(f, b);
  // if graph is undirected, don't include these
  Edge gd(g, d);
  Edge ge(g, e);
  
  graph.addNode(c);
  graph.addNode(d);
  graph.addNode(e);
  graph.addNode(f);
  graph.addNode(g);
  
  graph.addEdge(ab);
  graph.addEdge(ac);
  graph.addEdge(bc);
  graph.addEdge(ae);
  graph.addEdge(ce);
  graph.addEdge(cd);
  graph.addEdge(dg);
  graph.addEdge(eg);
  graph.addEdge(df);
  graph.addEdge(fb);
  graph.addEdge(gd);
  graph.addEdge(ge);

  graph.setDirected(true);

  set<Edge*> edges = graph.getAdjacentEdges(a);
  cout << "Edges adjacent to " << a << endl;
  for (set<Edge*>::iterator it = edges.begin(); it != edges.end(); it++) {
    Edge* eptr = *it;
    Edge edge = *eptr;
    cout << edge << endl;
  }
}

SUITE_BEGIN("Graphs")

TEST_BEGIN("SanityCheck")
{

}TEST_END

SUITE_END

int main (int argc, char* argv[])
{	
  if (argc == 2 && argv[1] == string("--manual")) {
    manual();
  } else {
    UTFrameworkInit;
  }
}
