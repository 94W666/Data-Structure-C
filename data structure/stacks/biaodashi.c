#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void Push(int x) {
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int Pop() {
    if (top == NULL) return 0;
    struct Node *temp = top;
    int data = temp->data;
    top = temp->next;
    free(temp);
    return data;
}

int Perform(char c, int num1, int num2) {
    if (c == '+') return (num1 + num2);
    if (c == '-') return (num1 - num2);
    if (c == '*') return (num1 * num2);
    if (c == '/') return (num1 / num2);
    return 0;
}
int main() {
    char *tokens[] = {"128", "64", "/", "1", "+", "2", "*"};
    
    for (int i = 0; i < 7; i++) {
        char *token = tokens[i];
        
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || 
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            int num2 = Pop();
            int num1 = Pop();
            int result = Perform(token[0], num1, num2);
            Push(result);
        } else {
            int num = atoi(token);
            Push(num);
        }
    }
    printf("结果: %d\n", top->data);
    return 0;
}