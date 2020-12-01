#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#define MAX 80
using namespace std;
void inToPostfix(char*, char*);
int priority(char); 
double Eval(char*); 
double cal(char, double, double); 

int main(int argc, char *argv[]) {
	
	char itemset[MAX] = {'\0'}; 

    
    char a;
     for(int i=0;i<11;i++)
     {
       cin>>a;
       itemset[i]=a;
     }

    cout<<Eval(itemset);

	return 0;
}

void inToPostfix(char* infix, char* postfix) { 
    char stack[MAX] = {'\0'};
    int i, j, top;
    for(i = 0, j = 0, top = 0; infix[i] != '\0'; i++){
			 switch(infix[i]) { 
        case '(':
            stack[++top] = infix[i]; 
            break; 
        case '+': case '-': case '*': case '/': 
            while(priority(stack[top]) >= priority(infix[i])) { 
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
  	}
    while(top > 0) { 
        postfix[j++] = stack[top--];
    }
} 

int priority(char op) { 
    switch(op) { 
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default:            return 0;
    } 
} 

double Eval(char infix[]) {
    char postfix[MAX]= {'\0'};
    char opnd[2] = {'\0'};
    double stack[MAX] = {0.0}; 
    
    inToPostfix(infix, postfix);    

    int top, i;
    for(top = 0, i = 0; postfix[i] != '\0'; i++){
		 switch(postfix[i]) { 
        case '+': case '-': case '*': case '/': 
            stack[top - 1] = cal(postfix[i], stack[top - 1], stack[top]); 
            top--; 
            break; 
        default: 
            opnd[0] = postfix[i];
            stack[++top] = atof(opnd);
   	 }  
		}
    
    return stack[top];
}

double cal(char op, double p1, double p2) { 
    switch(op) { 
        case '+': return p1 + p2; 
        case '-': return p1 - p2; 
        case '*': return p1 * p2; 
        case '/': return p1 / p2; 
    } 
}

