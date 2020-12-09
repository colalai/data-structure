#include <iostream>
using namespace std;
class BinTree
{
private:
    int arr[100];
    int tail;
   

public:
    void BuildTree(int data[], int n);
    void Print();
    
};

void BinTree::BuildTree(int data[], int n)
{
    int temp, node = 0;
    for (int i = 0; i < 100; i++)
        arr[i] = 0;
    arr[1] = data[0];
    temp = n;
    for (int i = 1; i < n; i++)
    {
        node = 1;
        while (arr[node] != 0)
        {
            if (data[i] > arr[node])
                node = 2 * node + 1;
            else
                node = 2 * node;
            if (temp < node)
            {
                temp = node;
                tail = temp;
            }
        }
        arr[node] = data[i];
    }
}
void BinTree::Print()
{
    for (int i = 1; i <= tail; i++)
        cout << arr[i] << " ";
}
int main(int argc, char* argv[])
{
    BinTree tree1;
    int n;
    cin >> n;
    int data[n];
    for (int i = 0; i < n; i++) cin >> data[i];
    tree1.BuildTree(data, n);
    tree1.Print();
}
//8 4 6 5 9 7 11 2 1
