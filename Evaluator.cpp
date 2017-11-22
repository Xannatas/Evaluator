#include <stack>
#include "Evaluator.h"
#include <iostream>
#include <math.h>

using namespace std;

/* Allison Collier / Isaiah Banta */
/* Our above and beyond is the POW Operator. Works for both positive and negative numbers*/
/* Also follows order of operations PEMDAS */

// Constructor. Set error flag to false.
Evaluator::Evaluator() {
 error=false;
}

// Push a number onto the num stack.
void Evaluator::num(double d) {
 nums.push(d);
}

// Evaluate an operator.//decides do I push onto the op stack or do I pop it
void Evaluator::op(int i) {
 if (ops.empty() == true) {ops.push(i);}
 else if (push_op(i, ops.top())) {
  ops.push(i);
 }
 else {
  while(!ops.empty() && !push_op(i, ops.top())) {
   execute_op();
   }
  if(i==RPN) {ops.pop();}
  else {ops.push(i);}
 }
}


// Finish remaining ops, return result.
double Evaluator::finish() {
 double result;
 while(!ops.empty()) {
  execute_op(); 
 }
 return nums.top();
}

// Reset stacks, error.
void Evaluator::reset() {
 while(nums.empty() == false) {
  nums.pop();
 }
 while(ops.empty() == false) {
  ops.pop();
 }
 error = false;
}

// Returns current value of error
bool Evaluator::problem() {
 return error;
}

// Compare top op to incoming op, if incoming op is of higher
// precedence (check prec[inc][top] of table), return true, otherwise
// return false.
bool Evaluator::push_op(int inc, int top) {
 if (prec[inc][top]) {return true;}
 else {return false;}
 
}

// Execute the top operator on the op stack, set error to true if
// necessary.
void Evaluator::execute_op() {
 if (ops.top() == UNK) {error = true;}
 else {
  int temp =1;
  double num1 = nums.top();
  double num2 =1;
  int op = ops.top();
  double result;
  switch(op) {
   case ADD:
    ops.pop();
    nums.pop();
    if(!nums.empty()){
    num2 = nums.top();
    nums.pop();
    result = num1 + num2;
}
else{error=true;
}
    break;
   case SUB:
    ops.pop(); 
    nums.pop();
    if(!nums.empty()){
    num2=nums.top();
    nums.pop();
    result = num2 - num1;
	}
	else{error=true;
	}
    break;
   case MLT:
    ops.pop();
    nums.pop();
    if(!nums.empty()){
    num2=nums.top();
    nums.pop();
    result = num1 * num2;
}
else{error=true;
}
    break;
   case DIV:
    ops.pop();
    nums.pop();
    if(!nums.empty()){
    num2=nums.top();
    nums.pop();
    if(num1==0){error=true;}
    else{result = num2 / num1;}
}
else{error=true;
}
    break;
   case UNM:
    nums.pop();
    result = -num1;
    ops.pop();
    break;
   case PWR:
    ops.pop();
    nums.pop();
    num2=nums.top();
    nums.pop();
    result = pow(num2, num1);
    break;
  }
   nums.push(result);
 }
}

