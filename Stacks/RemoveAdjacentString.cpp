//1047 leetcode problem: Remove All Adjacent Duplicates In String
#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;

string removeDuplicates(string &s)
{
    stack<char> st;
    for(char ch:s)
    {
        if(!st.empty() && st.top()==ch)
        {
            st.pop();
        }
        else{
            st.push(ch);
        }
    }

    string ans="";
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string s = "azxxzy";
    string ans = removeDuplicates(s);
    cout<<ans<<endl;
    return 0;
}