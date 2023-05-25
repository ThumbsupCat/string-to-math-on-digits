# String to Mathematical expression convertor (C) digits only

This implementation is based on the shunting yard algorithm that produces a postfix notation from an infix notation(the way we are used to).

Example:

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
 
 
    
