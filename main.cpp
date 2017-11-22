#include <iostream>
#include "Tokenizer.h"
#include "Evaluator.h"

using namespace std;



int main() {
 double a;
 Tokenizer tokenizer;
 Evaluator expression;
 while(true) {
  tokenizer.reset();
  expression.reset();
  cout << "Enter infix expression: ";
  if(cin.peek() == NEWLINE) {
   cout << "Exiting..." <<endl;
   return 0; 
  }
  while(tokenizer.type()!=ERR && tokenizer.type()!=END) {
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

