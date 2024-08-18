#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> a = {0,9,0,0,3,5};
    vector<int> b = {2,2,7};
    vector<int> ans;
    int carry = 0;
    int digit;
    int i = a.size()-1;
    int j = b.size()-1;

    while(i>=0 && j>=0)
    {
        int x = carry+a[i]+b[j];
        carry = x/10;
        digit = x%10;
        ans.push_back(digit);
        i--;
        j--;

    }

    while(i>=0)
    {
        int x = carry+a[i]+0;
        carry = x/10;
        digit = x%10;
        ans.push_back(digit);
        i--;
    }

    while(j>=0)
    {
        int x = carry+b[j]+0;
        carry = x/10;
        digit = x%10;
        ans.push_back(digit);
        j--;
    }

    while(carry>0)
    {
        ans.push_back(carry%10);
        carry = carry/10;
    }
    
    while(ans[ans.size()-1] == 0)
    {
        ans.pop_back();
    }

    reverse(ans.begin(),ans.end());

    
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }


}