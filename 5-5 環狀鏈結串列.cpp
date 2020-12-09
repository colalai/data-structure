#include <iostream>
using namespace std;

class ListNode
{
public:
    ListNode(int a) { data = a; link = 0; }
private:
    int data;
    ListNode* link;
    friend class CircularList;
};
class CircularList
{
public:
    CircularList();
    void InsertFirst(int x);
    void InsertLast(int x);
    void DeleteFirst();
    void DeleteLast();
    void PrintList();
private:
    ListNode* last;
};
CircularList::CircularList()
{
    last = 0;
}
void CircularList::InsertFirst(int x)
{
    if (last == 0)
    {
        ListNode* newNode = new ListNode(x);
        last = newNode;
        last->link = last;
    }
    else {
        ListNode* newNode = new ListNode(x);
        newNode->link = last->link;
        last->link = newNode;
    }


}
void CircularList::InsertLast(int x)
{
    if (last == 0)
    {
        ListNode* newNode = new ListNode(x);
        last = newNode;
        last->link = last;
    }
    else {
        ListNode* newNode = new ListNode(x);
        newNode->link = last->link;
        last->link = newNode;
        last = newNode;
    }
}
void CircularList::DeleteFirst()
{
    ListNode* current = last->link;
    last->link = current->link;
    delete current;
}
void CircularList::DeleteLast()
{
    ListNode* p ;
    ListNode* prev;
    ListNode* current = last->link;

    do {
        p = prev;
        prev = current;
        current = current->link;
    } while (current != last->link);
    p->link = prev->link;
    delete prev;
    last = p;
}
void CircularList::PrintList()
{
    ListNode* current = last->link;

    do {
        cout << current->data << " ";
        current = current->link;
    } while (current != last->link);
    cout << endl;
}
int main(int argc, char* argv[])
{
    CircularList list;
    int times, input;
    for (cin >> times; times > 0; times--) { cin >> input; list.InsertFirst(input); }
    for (cin >> times; times > 0; times--) list.DeleteFirst();
    for (cin >> times; times > 0; times--) { cin >> input; list.InsertLast(input); }
    for (cin >> times; times > 0; times--) list.DeleteLast();
    list.PrintList();
}
