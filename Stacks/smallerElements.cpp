#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> input)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(input.size());

    //right to left array iteration
    for(int i=input.size()-1;i>=0;i--)
    {
        int curr = input[i];
        while(s.top()>=curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

vector<int> previousSmallerElement(vector<int> input)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(input.size());

    //right to left array iteration
    for(int i=0;i<input.size();i++)
    {
        int curr = input[i];
        while(s.top()>=curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main()
{
    vector<int> input;
    input.push_back(4);
    input.push_back(8);
    input.push_back(5);
    input.push_back(2);
    input.push_back(25);
    vector<int> ans1 = nextSmallerElement(input);
    cout<<"Printing next smaller elements"<<endl;
    for(int i=0;i<input.size();i++)
    {
        cout<<ans1[i]<<" ";
    }
    cout<<endl;

    vector<int> ans2 = previousSmallerElement(input);
    cout<<"Printing previous smaller elements"<<endl;
    for(int i=0;i<input.size();i++)
    {
        cout<<ans2[i]<<" ";
    }
    cout<<endl;
    return 0;
}