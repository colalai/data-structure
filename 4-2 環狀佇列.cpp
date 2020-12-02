#include <iostream>
using namespace std;
class Queue {
public:
    void Enqueue(int x);
    int Dequeue();
    void PrintQueue();
private:
    int arr[10], rear = 0, front = 0;
};

void Queue::Enqueue(int x)
{
    arr[rear] = x;
    rear = (rear + 1) % 10;
    
}
int Queue::Dequeue()
{
    front = (front + 1) % 10;
    return arr[front];
    
}
void Queue::PrintQueue()
{
    for (int i =front; i !=rear; i=(i+1)%10)
    {
        cout << arr[i] << " ";
       
    }
    cout << "rear:" << rear << " " << "front:" << front;

}
int main(int argc, char* argv[])
{
    Queue queue;
    int times, input;
    for (int i = 0; i < 2; i++) {
        cin >> times;
        for (int j = 0; j < times; j++) {
            cin >> input;
            queue.Enqueue(input);
        }
        cin >> times;
        for (int j = 0; j < times; j++) {
            queue.Dequeue();
        }
    }
    queue.PrintQueue();
}
