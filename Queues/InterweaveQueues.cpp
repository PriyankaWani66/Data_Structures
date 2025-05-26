#include<queue>
#include<stack>
#include<iostream>
using namespace std;

void interweave(queue<int> &q)
{
    int n = q.size();
    int k = n/2;
    int count=0;
    queue<int> q2;
    if(q.empty())
    {
        return;
    }
    //step 1: split the queue into two halves and push first half into other queue
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        q2.push(temp);
        count++;
        if(count==k)
        {
            break;
        }
    }

    //step 2: interweave
    while(!q.empty() && !q2.empty())
    {
        int first = q2.front();
        q2.pop();
        q.push(first);

        int second = q.front();
        q.pop();
        q.push(second);
    }

    //odd size
    if(n&1)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }

}
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    int k = 5;
    interweave(q);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}