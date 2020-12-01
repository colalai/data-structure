#include <iostream>
using namespace std;
#define MAXNum 20
int Stack[MAXNum];
int Top = -1;
int Transfer(char*);
int Pop(void);
void Push(int);
int Transfer(char postfix[])
{
    
    char*pt = postfix;
    int opd1,opd2;
    while(*pt){
        if(*pt>='0'&&*pt<='9')
            Push(*pt-'0');
        else{
            opd1=Pop();
            opd2=Pop();
            switch(*pt){
                case'+':Push(opd1+opd2);
                    break;
                case'-':Push(opd1-opd2);
                    break;
                case'*':Push(opd1*opd2);
                    break;
                case'/':Push(opd1/opd2);
                    break;
                default:return-1;
            }
        }
        pt++;
    }
    return Pop();
}
int Pop(void){

    if (Top == -1) {
    }
    return Stack[Top--];
}
void Push(int n){

    if (Top == 20 - 1) {
    }
    Stack[++Top] = n;
}
int main(int argc, char *argv[])
{
    
   char itemset[20];
   scanf("%s", itemset);
   printf("%d",Transfer(itemset));
}
