#include<iostream>
using namespace std;

class Stack{
    private:
    int* arr;
    int size;
    int top;

    public:
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int data)
    {
        if(size-top>1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout<<"Stack overflow"<<endl;
        }
    }

    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack underflow"<<endl;
        }
        else
        {
            top--;
        }
    }

    int getTop()
    {
        if(top==-1)
        {
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        else
        {
            return arr[top];
        }
    }

    int getSize()
    {
        return top+1;
    }

    bool isEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    //CREATION
    Stack s(5);

    //insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    //s.push(60);

    while(!s.isEmpty()) {
            cout << s.getTop() << " ";
            s.pop();
    }cout << endl;

    cout << "Size of stack " << s.getSize() << endl;

    s.pop();

    return 0;
}