#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack <int>& s, int& target)
{
    //B.C
    if(s.size()==0)
    {
        s.push(target);
        return;
    }

    if(s.top()>=target)
    {
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();

    //recursion
    insertSorted(s,target);

    //push temp
    s.push(temp);
}

void sort(stack <int>& s)
{
    //B.c
    if(s.empty())
    {
        return;
    }

    int target = s.top();
    s.pop();

    //recusion
    sort(s);

    //insert at bottom
    insertSorted(s,target);
}
int main()
{
    stack <int> s;
    s.push(43);
    s.push(1);
    s.push(10);
    s.push(4);
    s.push(9);

    sort(s);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}