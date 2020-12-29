#include <iostream>
using namespace std;

class ListNode
{
public:
    ListNode(int a) {data = a; link = 0;}
private:
    int data;
    ListNode *link;
    friend class CircularList;
};
class CircularList
{
public:
    void InsertFirst(int x);
    void InsertLast(int x);
    void DeleteFirst();
    void DeleteLast();
    void PrintList();
    void Reverse();
private:
    ListNode *last=0;
};

void CircularList::InsertFirst(int x)
{
    
    ListNode* newnode=new ListNode(x);
    if(last==0)
    {
        last=newnode;
        last->link=newnode;
    }
    newnode->link=last->link;
    last->link=newnode;
    
        
}
void CircularList::InsertLast(int x)
{
    ListNode* newnode=new ListNode(x);
    if(last==0)
    {
        last=newnode;
        last->link=newnode;
    }
    else
    {
        newnode->link=last->link;
        last->link=newnode;
        last=newnode;
    }
}
void CircularList::DeleteFirst()
{
    ListNode* current=last->link;
    last->link=last->link->link;
    delete current;
    
}
void CircularList::DeleteLast()
{
    ListNode* prev=last;
    ListNode* current=last->link;
    while(current->link!=last)
    {
        current=current->link;
    }
    current->link=last->link;
    delete prev;
    last=current;

}
void CircularList::PrintList()
{
    ListNode* current=last;
    do{
        current=current->link;
        cout<<current->data<<" ";
    }while(current!=last);
}

int main(int argc, char *argv[])
{
    CircularList list;
    int times, input;
    for(cin >> times; times > 0; times--) {cin >> input; list.InsertFirst(input);}
    for(cin >> times; times > 0; times--) list.DeleteFirst();
    for(cin >> times; times > 0; times--) {cin >> input; list.InsertLast(input);}
    for(cin >> times; times > 0; times--) list.DeleteLast();
    list.PrintList();
}
