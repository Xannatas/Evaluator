#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <stack>
#include "Tokenizer.h"

using namespace std;

// Global precedence const array, uses op defines in Tokenizer.h
// Set this to the total number of operators.
#define PREC_DIM 9
static const bool prec[PREC_DIM][PREC_DIM] =
{           /* ADD SUB MLT DIV UNM LPN RPN PWR */
  /* ADD */ {   0,  0,  0,  0,  0,  1,  0,  0}, 
  /* SUB */ {   0,  0,  0,  0,  0,  1,  0,  0}, 
  /* MLT */ {   1,  1,  0,  0,  0,  1,  0,  0}, 
  /* DIV */ {   1,  1,  0,  0,  0,  1,  0,  0}, 
  /* UNM */ {   1,  1,  1,  1,  1,  1,  0,  0}, 
  /* LPN */ {   1,  1,  1,  1,  1,  1,  0,  1}, 
  /* RPN */ {   0,  0,  0,  0,  0,  1,  0,  0},
  /* PWR */ {   1,  1,  1,  1,  1,  1,  0,  0},
};

class Evaluator {
  public:
    // Constructor. Set error flag to false.
    Evaluator();

    // Push a number onto the num stack.
    void num(double);

    // Evaluate an operator.
    void op(int);

    // Finish remaining ops, return result.
    double finish();

    // Reset stacks, error.
    void reset();

    // Returns current value of error
    bool problem();

  private:
    // Error flag.
    bool error;
    // Compare top op to incoming op, if incoming op is of higher
    // precedence (check prec[inc][top] of table), return true, otherwise
    // return false.
    bool push_op(int inc, int top);
    // Execute the top operator on the op stack, set error to true if
    // necessary.
    void execute_op();
    // Op stack
    stack<int> ops;
    // Num stack
    stack<double> nums;




};

#endif
