#include <iostream>
#include "Tokenizer.h"
#include "Evaluator.h"

using namespace std;


//Main function prompting user for infix expression.
//Translates infix expression to postfix expression.
//Inserts the postfix expression onto the stack.
//Solves the expression by popping the items off of the stack.

int main() {
 double a;
 Tokenizer tokenizer;
 Evaluator expression;
 while(true) {		//Continues to prompt the user for new inputs until program is exited
  tokenizer.reset();
  expression.reset();
  cout << "Enter infix expression: ";
  if(cin.peek() == NEWLINE) {
   cout << "Exiting..." <<endl;
   return 0; 
  }
  while(tokenizer.type()!=ERR && tokenizer.type()!=END) {	//While not an error or not end of stream
   tokenizer.next();
   switch(tokenizer.type()) {
    case NUM:
     expression.num(tokenizer.num_read());
     break;
    case OP:
     expression.op(tokenizer.op_read());
     break;
    case ERR:
     while(cin.peek()!=NEWLINE) {
      cin.ignore();
     }
     cout << "An error has been encountered." <<endl;
     break;
    case END:
    a = expression.finish();
    if(expression.problem()){
    	while(cin.peek()!=NEWLINE){
    		cin.ignore();
		}
    	cout << "An error was encoutnered." << endl;
	}
	else{
     cout << "Result: " <<a<<endl;
     break;
 }
   }
  }
 cin.ignore();
 }
}

