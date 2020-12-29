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
private:
    ListNode *first=0,*last=0;
};
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
}
int main(int argc, char *argv[])
{
    LinkedList list;
    int times, input;
    for(cin >> times; times > 0; times--) {cin >> input; list.InsertFirst(input);}
    for(cin >> times; times > 0; times--) list.DeleteFirst();
    for(cin >> times; times > 0; times--) {cin >> input; list.InsertLast(input);}
    for(cin >> times; times > 0; times--) list.DeleteLast();
    list.PrintList();
}
