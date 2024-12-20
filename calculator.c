#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

int getPrecedence(char operator)
{
    int precedence = -1;
    switch (operator)
    {
    case '+':
    case '-':
        precedence = 1;
        break;
    case '*':
    case '/':
        precedence = 2;
        break;
    }
    return precedence;
}

int performOperation(int operand1, int operand2, char operator)
{
    int result = 0;
    switch (operator)
    {
    case '*':
        result = operand1 * operand2;
        break;
    case '+':
        result = operand1 + operand2;
        break;
    case '-':
        result = operand1 - operand2;
        break;
    case '/':
        if (operand2 == 0)
        {
            printf("Error: Division by zero.\n");
            exit(1);
        }
        result = operand1 / operand2;
        break;
    default:
        break;
    }
    return result;
}

int evaluateExpression(char *expression)
{
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isspace(expression[i]))
        {
            printf("Error: Invalid expression due to spaces.\n");
            return -999999;
        }
    }

    int valueStack[SIZE], valueTop = -1;
    char operatorStack[SIZE], operatorTop = -1;

    for (int i = 0; expression[i] != '\0'; i++)
    {
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
    input[strcspn(input, "\n")] = '\0';
    int result = evaluateExpression(input);
    if (result != -999999)
    {
        printf("Result: %d\n", result);
    }
    return 0;
}
