#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack <int>& s, int& target)
{
    //B.C
    if(s.size()==0)
    {
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();

    //recursion
    insertAtBottom(s,target);

    //push temp
    s.push(temp);
}

int main()
{
    stack <int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    int target = s.top();
    s.pop();

    insertAtBottom(s,target);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}