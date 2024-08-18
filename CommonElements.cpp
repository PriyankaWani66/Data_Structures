//Common elements in three sorted array - geeks for geeks question.

#include<iostream>
#include<set>
using namespace std;

int main()
{
    int a [] = {3,3,3};
    int b [] = {3,3,3};
    int c [] = {3,3,3};

    int n = 3;
    int m = 3;
    int l = 3;

    int i = 0;
    int j = 0;
    int k = 0;
    set<int> st;
    while(i<n && j<m && k<l)
    {
        if(a[i]==b[j] && b[j]==c[k])
        {
            st.insert(a[i]);
            i++; j++; k++;
        }
        else if(a[i]<b[j])
        {
            i++;
        }
        else if(b[j]<c[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    
    for(auto value : st)
    {
        cout<<value<<" ";
    }
}