#ifndef __fsm_h__
#define __fsm_h__

#include <string>
#include <iostream>

#include "UTFramework.h"

using namespace std;

// forward declarations

// class definitions
class FSM {
private:
  
public:
  // ----- Constructor and Deconstructor

  FSM();
  ~FSM();

  // ----- Add state and transition information

  /**
   * Adds a state with the given label. The is_accept_state parameter
   * tells us if this is an 'acceptable' state.
   *
   * If this is a duplicate state (e.g. another state in the FSM has
   * the same label), this function has no effect.
   *
   * return the number of states the FSM contains after this one has
   * been added. 
   **/
  int addState(string label, boolean is_accept_state);

  /**
   * Adds a state with the given label. This is equivalent to
   * addState(label, false). See the other addState function for
   * remaining documentation.
   **/
  int addState(string label);

  /**
   * Adds a transition between two states that activates when the
   * given signal is received.
   *
   * stateA: the start state. The FSM must be in this state for the
   *         transition to take place.  
   *
   * stateB: the end state. After taking the transition, the FSM will
   *         be placed in stateB.
   *
   * signal: the signal that (assuming we are in stateA) will trigger
   *         this particular transition.
   *
   * transLabel: the label for this transition. Can be used for
   *             debugging.
   **/
  int addTransition(string stateA, string stateB, 
		    int signal, string transLabel);

  
  
};
#endif

