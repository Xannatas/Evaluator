#include "Tokenizer.h"
#include <iostream>

// Allison Collier , Isaiah Banta


using namespace std;

//Constructor. 
//Initializes <end> (for end of infix expression) to false.
//Initializes unary minus to true, (if no number before '-', UNM = true).
//Initializes the LPN and RPN counters to 0. 
Tokenizer::Tokenizer() {
 token_type = NUM;
 end = false;
 unary_minus = true;
 lpn_count = 0;
 rpn_count = 0;
}

//Prompts the user for an infix expression.
void Tokenizer::prompt() const {
 cout << "Enter infix expressions: ";
}

//Checks the next number or operator.
//If the character is \n, then we are done.
//If it is a number then it stores the number as itself.
//Otherwise, it is an operator, and we assign an op code.
void Tokenizer::next() {
 eat_spaces();
 char temp;
 temp = char(cin.peek());       //Sets temp equal to the next char
 if (temp==NEWLINE) {
  end = true;
  token_type = END;
  unary_minus = true;
}
 else if (('0'<=temp && '9'>=temp) || temp == '.') {
  token_type = NUM;
  cin >> num;
  unary_minus = false;
 }
 else {
  token_type=OP;        //All of these token types were defined in the Tokenizer.h file
  switch(temp) {
   case ADD_CHAR:
    unary_minus = true;
    op = ADD;
    break;
   case MLT_CHAR:
    unary_minus = true;
    op = MLT;
    break;
   case DIV_CHAR:
    unary_minus = true;
    op = DIV;
    break;
   case LPN_CHAR:
    unary_minus = true;
    op = LPN;
    lpn_count += 1;
    break;
   case RPN_CHAR:
    unary_minus = false;
    op = RPN;
    rpn_count += 1;
    break;
   case PWR_CHAR:
    unary_minus = true;
    op = PWR;
    break;
   case FCT_CHAR:
    unary_minus = false;
    op = FCT;
    break;
   case MOD_CHAR:
    unary_minus = true;
    op = MOD;
    break;

   case SUB_CHAR:
    if(unary_minus == true) {
     op = UNM;
    }
    else {
     op = SUB;
     unary_minus = true;
    }
    break;
   default:
    token_type = ERR;
    break;
  }
  cin.get();
 }
}

//Returns the token type.
int Tokenizer::type() const {
 return token_type;
}

//Returns the number.
double Tokenizer::num_read() const{
 return num;
}

//Returns the operator. 
int Tokenizer::op_read() const{
 return op;
}

//Returns the number of left parenthesis.
int Tokenizer::lpn_counter(){
 return lpn_count;
}

//Returns the number of right parenthesis.
int Tokenizer::rpn_counter(){
 return rpn_count;
}
 
//Removes spaces from user input.
void Tokenizer::eat_spaces() const{
 while(char(cin.peek()) == SPC) {cin.ignore();}
}

//Resets the values initialized in the constructor
void Tokenizer::reset() {
 end = false;
 token_type = NUM;
 unary_minus = true;
 rpn_count = 0;
 lpn_count = 0;
}

//Returns the boolean value of <end>.
bool Tokenizer::end_of_stream() const{
 return end;
}
