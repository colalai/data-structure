#include <iostream>
using namespace std;
class MaxHeap
{
public:
    void Insert(int x);
    void Print();

private:
    int arr[100];
    int tail=0;




};
void MaxHeap::Insert(int x)
{
    int current=++tail;
    while(current!=1 && arr[current/2]<x)
    {
        arr[current]=arr[current/2];
        current/=2;
    }
    arr[current]=x;
}
void MaxHeap::Print()
{
    for (int i = 1; i <= tail; i++)
    {
        cout << arr[i] << " ";
    }
}

int main(int argc, char* argv[])
{
    MaxHeap tree1;
    int times, input;
    for (cin >> times; times > 0; times--) { cin >> input; tree1.Insert(input); }
    tree1.Print();
}
