#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

int getPrecedence(char operator)
{
    switch (operator)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

int performOperation(int operand1, int operand2, char operator)
{
    switch (operator)
    {
    case '*':
        return operand1 * operand2;
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '/':
        if (operand2 == 0)
        {
            printf("Error: Division by zero.\n");
            exit(1);
        }
        return operand1 / operand2;
    default:
        return 0;
    }
}

int evaluateExpression(char *expression)
{
    int valueStack[SIZE], valueTop = -1;
    char operatorStack[SIZE], operatorTop = -1;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isspace(expression[i]))
            continue;

        if (isdigit(expression[i]))
        {
            int number = 0;
            while (i < strlen(expression) && isdigit(expression[i]))
            {
                number = number * 10 + (expression[i] - '0');
                i++;
            }
            valueStack[++valueTop] = number;
            i--;
        }
        else if (strchr("+-*/", expression[i]))
        {
            while (operatorTop >= 0 && getPrecedence(operatorStack[operatorTop]) >= getPrecedence(expression[i]))
            {
                int operand2 = valueStack[valueTop--];
                int operand1 = valueStack[valueTop--];
                char operator= operatorStack[operatorTop--];
                valueStack[++valueTop] = performOperation(operand1, operand2, operator);
            }
            operatorStack[++operatorTop] = expression[i];
        }
        else
        {
            printf("Error: Invalid expression.\n");
            return -999999;
        }
    }

    while (operatorTop >= 0)
    {
        int operand2 = valueStack[valueTop--];
        int operand1 = valueStack[valueTop--];
        char operator= operatorStack[operatorTop--];
        valueStack[++valueTop] = performOperation(operand1, operand2, operator);
    }

    return valueStack[valueTop];
}

int main()
{
    char input[SIZE];
    printf("Enter an expression: ");
    fgets(input, SIZE, stdin);
    int result = evaluateExpression(input);
    if (result != -999999)
    {
        printf("Result: %d\n", result);
    }
    return 0;
}
