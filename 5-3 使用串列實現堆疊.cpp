#include <iostream>
using namespace std;

class ListNode
{
public:
    ListNode(int a) {data = a; link = 0;}
private:
    int data;
    ListNode *link;
    friend class LinkedList;
};
class LinkedList
{
public:
    void InsertFirst(int x);
    void InsertLast(int x);
    void DeleteFirst();
    void DeleteLast();
    void PrintList();
    void Reverse();
private:
    ListNode *first=0,*last=0;
};
class Stack :LinkedList
{
public:
    void Push(int x);
    void Pop();
    void PrintStack();
};
void Stack::Push(int x)
{
    InsertLast(x);
}
void Stack::Pop()
{
    DeleteLast();
    
}
void Stack::PrintStack()
{
    PrintList();
}
void LinkedList::InsertFirst(int x)
{
    ListNode* newnode=new ListNode(x);
    newnode->link=first;
    first=newnode;
    if(last==0)
        last=newnode;
}
void LinkedList::InsertLast(int x)
{
    ListNode* newnode=new ListNode(x);
    if(last==0)
    {
        first=newnode;
        last=newnode;
    }
    else
    {
        last->link=newnode;
        last=newnode;
    }
}
void LinkedList::DeleteFirst()
{
    ListNode* current=first;
    first=first->link;
    delete current;
    
}
void LinkedList::DeleteLast()
{
    ListNode* current=first;
    while(current->link!=last)
    {
        current=current->link;
    }
    delete current->link;
    current->link=0;
    last=current;

}
void LinkedList::PrintList()
{
    ListNode* current=first;
    while(current!=0)
    {
        cout<<current->data<<" ";
        current=current->link;
    }
    cout<<'\n';
}
void LinkedList::Reverse()
{
    ListNode *current=first,*prev=0;
    while(current)
    {
        ListNode *p=prev;
        prev=current;
        current=current->link;
        prev->link=p;
    }
    first=prev;
}
int main(int argc, char *argv[])
{
    Stack stack;
    int times, input;
    for(cin >> times; times > 0; times--) {cin >> input; stack.Push(input);}
    for(cin >> times; times > 0; times--) stack.Pop();
    stack.PrintStack();
}
