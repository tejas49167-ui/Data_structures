#include <stdio.h>
#include <stdlib.h>

void convertInfixToPostfix();
void push(char symbol);
char pop();
int getPrecedence(char operator);

char infixExpression[30], postfixExpression[30], operatorStack[30];
int top = -1;

int main()
{
    printf("\nEnter a valid infix expression: ");
    scanf("%s", infixExpression);

    convertInfixToPostfix();

    printf("\nThe entered infix expression is:\n%s", infixExpression);
    printf("\nThe corresponding postfix expression is:\n%s\n", postfixExpression);

    return 0;
}

void convertInfixToPostfix()
{
    int infixIndex = 0, postfixIndex = 0;
    char currentSymbol, poppedSymbol;

    push('#');  // Stack bottom marker

    while (infixExpression[infixIndex] != '\0')
    {
        currentSymbol = infixExpression[infixIndex];

        switch (currentSymbol)
        {
            case '(':
                push(currentSymbol);
                break;

            case ')':
                poppedSymbol = pop();
                while (poppedSymbol != '(')
                {
                    postfixExpression[postfixIndex++] = poppedSymbol;
                    poppedSymbol = pop();
                }
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
            case '$':
                while (getPrecedence(operatorStack[top]) >= getPrecedence(currentSymbol))
                {
                    poppedSymbol = pop();
                    postfixExpression[postfixIndex++] = poppedSymbol;
                }
                push(currentSymbol);
                break;

            default: // Operand
                postfixExpression[postfixIndex++] = currentSymbol;
        }
        infixIndex++;
    }

    while (top > 0)
    {
        poppedSymbol = pop();
        postfixExpression[postfixIndex++] = poppedSymbol;
    }

    postfixExpression[postfixIndex] = '\0';  // Null terminate postfix string
}

void push(char symbol)
{
    operatorStack[++top] = symbol;
}

char pop()
{
    return operatorStack[top--];
}

int getPrecedence(char operator)
{
    switch (operator)
    {
        case '#': return -1;
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '^':
        case '$': return 3;
        default: return 0;
    }
}
