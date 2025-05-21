#include<iostream>
#include<stack>
using namespace std;

void findMiddleElement(stack <int>&s, int &totalSize)
{
    //B.c
    if(s.size()==totalSize/2 + 1)
    {
        cout<<"middle element: "<<s.top()<<endl;
        return;
    }

    int temp = s.top();
    s.pop();
    //recursion
    findMiddleElement(s,totalSize);

    //push 
    s.push(temp);


}
int main()
{
    stack <int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    int totalSize = s.size();
    findMiddleElement(s,totalSize);

    return 0;
}