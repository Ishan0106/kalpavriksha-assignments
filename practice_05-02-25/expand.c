#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 100
void decodeString(char *s, char *result) {
    char stack[MAX_LEN][MAX_LEN];
    int numStack[MAX_LEN];
    int top = -1, numTop = -1;
    char current[MAX_LEN] = "";
    int num = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            strcpy(stack[++top], current);
            numStack[++numTop] = num;
            num = 0;
            current[0] = '\0';
        } else if (s[i] == ']') {
            int times = numStack[numTop--];
            char temp[MAX_LEN] = "";
            for (int j = 0; j < times; j++) {
                strcat(temp, current);
            }
            strcpy(current, stack[top--]);
            strcat(current, temp);
        } else {
            int len = strlen(current);
            current[len] = s[i];
            current[len + 1] = '\0';
        }
    }
    strcpy(result, current);
}
int main() {
    char str[1000];
    scanf("%s",str);
    char result[MAX_LEN];
    decodeString(str, result);
    printf("%s\n", result);
    return 0;
}


