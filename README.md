# String to Mathematical expression convertor (C) digits only

This implementation is based on the shunting yard algorithm that produces a postfix notation from an infix notation(the way we are used to).

# Infix to Postfix notation

I implemented this in the function:

    char *RPN(char *expression);

The function uses two stacks

    Stack *rpn
    Stack *operators
    
The rpn stack is the main stack which also becomes a postfix notation of the initial expression

The operators stack is used to store the operators but it has a few restrictions:
  - I want to respect the getPrecedence function which gives me the importance of the operator
    - If it has a better importance than the operator in the top of the stack, the element in the top of it will be pushed in the rpn stack
    - Else, the operator will just be pushed into the stack of operators
 
 In the for loop I got a few cases which I will review below:
  - If the character on the position i in the string is a digit
     - push into the rpn stack
  - If the character on the position i in the string is an operator, then I do the restriction mentioned above in the stacks descriptions
  - If the character on the position i in the string is a space, then I will just skip this character
  - If the character on the position i in the string is an opening parentheses '(', then it will have the same behaviour as a digit
  - If the character on the position i in the string is a closing parentheses, it has a few operations
    - I'm adding all operators from the operators stack to the main stack until I reach the opening parentheses
    - I'm popping the opening parentheses
  - If there's any other character that is unknown, I get an error message
 
 When the loop ends, I'm adding all remaining operators to the main stack
 Cleaning memory by destroying the stack
 Converting the stack into a string
 
# Mathematical String to result
I implemented the function in
  
    int eval(const char *expression);
    
Just like before, I get through a string, but this time, the postfix version of the initial one provided in the input
  
I'm using only one stack to store temporary values.
  
    Stack *stack
  
This time, in the for loop I got the following cases:
  - If it's a digit, I will push the operand in the stack, this time, I want the digit in the stack instead of its ASCII value in order to use it for compution
   - If it's an operator:
     - I want to make sure the stack is not empty, in other words, I want to have enough operands for the compution to take place
     - I pop from the stack both of the operands
     - I go into the switch and get the result of the operation found, if the operator is unknown, it gives an error message
   
   After I finish the for loop, the output is going to be on the top of the stack
   I pop it from the stack and store it in the result
   If the stack ends up not being empty, then the expression is wrong.
   I destroy the stack used

# Example:

  Input:
  
    (1+2)*3-4
    
  Output:
  
    12+3*4-

The output is used in order to compute the expression.

From output to the final output, I'm going to explain each step:

Step 1:

    1 is added to the stack
  
Step 2:

    2 is added to the stack
  
Step 3:

    Operator + found
  
    Second operand is taken from the top of the stack top(stack) = 2
  
    Popping the top of the stack
  
    First operand is taken from the top for the stack top(stack) = 1
  
     Popping the top of the stack
  
    Goes into the switch and does the operation that the operator suggests
  
      1 + 2 = 3
    
    The result is pushed into the stack
  
    The remaining string looks like this
      3*4-
    
    The stack looks likes this
      3
    
Step 4:

    3 is added to the stack
  
Step 5:

    Operator * found
    
    Second operand is taken from the top of the stack top(stack) = 3
    
    Popping the top of the stack
    
    First operand is taken from the top of the stack top(stack) = 3
    
    Popping the top of the stack
    
    Goes into the switch and does the operation that the operator suggests
    
     3 * 3 = 9
     
    The result is pushed into the stack
    
  
    The remaining string looks like this
    
      4-
   
    The stack looks likes this
    
      9
Step 6:

      4 is added to the stack
    
Step 7:
 
    Operator - found
    
    Second operand is taken from the top of the stack top(stack) = 9
    
    Popping the top of the stack
    
    First operand is taken from the top for the stack top(stack) = 4
    
    Popping the top of the stack
    
    Goes into the switch and does the operation that the operator suggests
    
       9 - 4 = 5
       
    The result is pushed into the stack

    The remaining string looks like this
    
      (NULL)
    
    The stack looks likes this
    
      5
      
Step 8:
    The string is NULL, so it leaves the for loop and the top(stack) has the expression's result
  
 END
  
  Output:
    
    5
 
 
    
