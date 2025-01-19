#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> ans;
    ans.push_back(1);

    int n;
    cout<<"Factorial of a number: "<<endl;
    cin>>n;
    int carry = 0;
    int digit;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<ans.size();j++)
        {
            int x = ans[j]*i + carry;
            ans[j] = x%10;
            carry = x/10;

        }
        while(carry>0)
        {
            ans.push_back(carry%10);
            carry = carry/10;
        }
    }

    reverse(ans.begin(),ans.end());

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}