#include<queue>
#include<stack>
#include<iostream>
using namespace std;

void reverseK(queue<int> &q, int k)
{
    int n = q.size();
    int count = 0;
    stack<int> s;

    if(k<=0 || k>n)
    {
        return;
    }
    //step 1: move only k elements to stack
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        s.push(temp);
        count++;
        if(count==k)
        {
            break;
        }
    }

    //step 2: push it back into q=> reversed elements
    while(!s.empty())
    {
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    //step 3: n-k elements to be pushed as it is into the queue
    count = 0;
    while (!q.empty() && n-k!=0)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;

        if(count==n-k)
        {
            break;
        }
    }
    
}
int main()
{
    queue<int> q;
    q.push(3);
    q.push(2);
    q.push(6);
    q.push(8);
    q.push(9);
    int k = 5;
    reverseK(q,k);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}