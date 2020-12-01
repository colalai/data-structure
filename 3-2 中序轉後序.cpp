#include <stdio.h> 
#include <stdlib.h> 

#define MAX 80

void InfixToPostfix(char*, char*);
int Priority(char);

int main(void) { 
    char itemset[20] = {'\0'}; 
    char postfix[20]= {'\0'}; 

    scanf("%s", itemset); 
    InfixToPostfix(itemset, postfix);
    
    int i;
    for(i = 0; postfix[i] != '\0'; i++) {
        printf("%c", postfix[i]); 
    }

    return 0; 
} 

void InfixToPostfix(char* infix, char* postfix) { 
    char stack[MAX] = {'\0'};
    int i, j, top;
    for(i = 0, j = 0, top = 0; infix[i] != '\0'; i++) switch(infix[i]) { 
        case '(':
            stack[++top] = infix[i]; 
            break; 
        case '+': case '-': case '*': case '/': 
            while(Priority(stack[top]) >= Priority(infix[i])) { 
                postfix[j++] = stack[top--];
            } 
            stack[++top] = infix[i];
            break; 
        case ')': 
            while(stack[top] != '(') {
                postfix[j++] = stack[top--];
            } 
            top--;  
            break; 
        default:  
            postfix[j++] = infix[i];
    }
    while(top > 0) { 
        postfix[j++] = stack[top--];
    }
} 

int Priority(char op) { 
    switch(op) { 
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default:            return 0;
    } 
} 
