#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
// MODIFY FOR NEW OP
// Operator codes.
#define ADD 0   //Addition
#define SUB 1   //Subtraction
#define MLT 2   //Multiplication
#define DIV 3   //Division
#define UNM 4   //Unary minus
#define LPN 5   //Left parenthesis
#define RPN 6   //Right parenthesis
#define PWR 7   //Exponent
#define FCT 8   //Factorial 
#define MOD 9   //Mod
#define UNK -1  //Unknown

// MODIFY FOR NEW OP CHARS
// Operator chars.
#define ADD_CHAR '+'
#define SUB_CHAR '-'
#define MLT_CHAR '*'
#define DIV_CHAR '/'
#define UNM_CHAR '-'
#define LPN_CHAR '('
#define RPN_CHAR ')'
#define PWR_CHAR '^' //Power operator character
#define FCT_CHAR '!' //Factorial operator character
#define MOD_CHAR '%' //Mod operator character

// Other useful char definitions.

// Space character
#define SPC ' '

// Newline character
#define NEWLINE '\n'

// MODIFY FOR NEW TOKEN TYPE
#define OP 0
#define NUM 1
#define ERR 2
#define END 3 

class Tokenizer {
  public:

    // Constructor. Set token_type to NUM, end to false, unary_minus to
    // true.
    Tokenizer();

    // Prompt for expression.
    void prompt() const;

    // Get next token from input stream.
    void next();

    // Return token type of most recently read token. NUM - number, OP -
    // operator, ERR - error, END - end of input, use define token type
    // codes at top of this file.
    int type() const;

    // Return most recently read number.
    double num_read() const;

    // Return most recently read op code. Return op code as defined at top
    // of this file.
    int op_read() const;

    // Return true if end of input encountered.
    bool end_of_stream() const;
    
    //Counts number of left parenthesis.
    int lpn_counter();

    //Counts number of right parenthesis.
    int rpn_counter();
    
    //Reset get token to initial conditions.
    void reset();

  private:
    
    //Contains the lpn_count number tracking the number of left parenthesis.
    int lpn_count;
    
    //Contains the rpn_count number tracking the number of right parenthesis.
    int rpn_count;
  
    // Set to:  NUM - number, OP - operator, ERR - error, END - end of
    // input, for most recently read token, uses define token type codes at
    // top of this file.
    char token_type;

    // Contains the op code of the most recent operator read from stream.
    // Negative if unrecognized.
    int op;

    // Contains the most recent number read from stream.
    double num;

    // True if new line encountered indicating end of stream.
    bool end;

    // True if next '-' character should be treated as a unary minus.
    bool unary_minus;

    // Return op code of operator starting with char, negative if
    // unrecognized operator. Must be consistent with OP codes at top of
    // this file.
    int op_code(char); 

    // Eat whitespaces. Cleans the expression string of leading spaces.
    void eat_spaces() const;

};


#endif
