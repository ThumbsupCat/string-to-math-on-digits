#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "Stack.h"


bool is_digit(char ch) {
    if (strchr("0123456789", ch))
        return true;
    return false;
}

bool is_space(char ch) {
    if(ch == ' ')
        return true;
    return false;
}

bool is_operator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return true;
    return false;
}

char *reverse(char* string) {
    int length = strlen(string);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }

    return string;
}

char* string_convertor(Stack* rpn_stack) {
    char *converted = calloc(rpn_stack->size + 1, sizeof(char));
    int k = 0;

    while(!isStackEmpty(rpn_stack)) {
        converted[k++] = pop(rpn_stack);
    }

    destroyStack(rpn_stack);

    return reverse(converted);
}

int getPrecedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

char *RPN(char expression[]) {
    int i;

    Stack* rpn = createStack();
    Stack* operators = createStack();

    for (i = 0; expression[i]; i++) {
        if (is_digit(expression[i])) {
            push(rpn, expression[i]);
        } else if (is_operator(expression[i])){
            while (!isStackEmpty(operators) && getPrecedence(top(operators)) >= getPrecedence(expression[i])) {
                push(rpn, pop(operators));
            }
            push(operators, expression[i]);

        } else if (is_space(expression[i])){
            continue;
        } else if (expression[i] == '(') {
            push(operators, expression[i]);
        } else if (expression[i] == ')') {
            while(!isStackEmpty(operators) && top(operators) != '(')
                push(rpn, pop(operators));
            if (!isStackEmpty(operators) && top(operators) == '(') {
                pop(operators);
            }
        } else {
            printf("Expresie matematica gresita");
        }
    }

    while (!isStackEmpty(operators)) {
        push(rpn, pop(operators));
    }

    destroyStack(operators);

    return string_convertor(rpn);

}

int eval(const char* expression) {
    int length = strlen(expression);
    int i;
    int operand1, operand2;
    int result;

    Stack* stack = createStack();

    for (i = 0; i < length; i++) {
        char ch = expression[i];

        if (is_digit(ch)) {
            int operand = ch - '0';
            push(stack, operand);
        } else if (is_operator(ch)) {
            if (isStackEmpty(stack)) {
                printf("Nu am destui operanzi\n");
                return 0; 
            }

            operand2 = pop(stack);

            if (isStackEmpty(stack)) {
                printf("Nu am destui operanzi\n");
                return 0; 
            }

            operand1 = pop(stack);

            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '^': {
                    int k = 1;
                    while(operand2 > 0) {
                        k *= operand1;
                        operand2--;
                    }
                    result = k;
                    break;
                }
                default:
                    printf("Operator necunoscut\n");
                    return 0;
            }

            push(stack, result);
        }
    }

    if (isStackEmpty(stack)) {
        printf("Stiva goala\n");
        return 0;
    }

    result = pop(stack);

    if (!isStackEmpty(stack)) {
        printf("Prea multi operanzi\n");
        return 0; 
    }

    destroyStack(stack);
    return result;
}

int main() {
    char *expression = malloc(100);
    scanf("%s", expression);
    char *string = RPN(expression);
    printf("\n%s\n", string);
    printf("\n%d\n", eval(string));
    free(string);
    free(expression);
    return 0;
}
