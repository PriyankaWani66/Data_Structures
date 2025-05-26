#include<queue>
#include<iostream>
using namespace std;

class Queue
{
    public:
    int front;
    int rear;
    int *arr;
    int size;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data)
    {
        if(rear==size) //full
        {
            cout<<"Queue is full"<<endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void pop()
    {
        if(rear==front)//empty
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            arr[front] = -1;
            front++;
            if(front==rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int getSize()
    {
        return rear-front;
    }

    bool isEmpty()
    {
        if(rear==front)
        {
            return true;
        }
        return false;
    }

    int getFront()
    {
        if(rear==front) //empty
        {
            cout<<"No elements"<<endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
};

int main()
{
    Queue q(8);

    q.push(5);
    q.push(10);

    cout<<q.getSize()<<endl;
    cout<<q.getFront()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
    q.pop();
    q.pop();
    cout<<q.isEmpty()<<endl;

}