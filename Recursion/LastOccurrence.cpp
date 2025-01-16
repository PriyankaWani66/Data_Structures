#include<iostream>
using namespace std;

void lastOccurrence_RTL(string &str, char &letter, int i, int &ans)
{
    //B.C
    if(i<0)
    {
        return;
    }
    //Recursion
    if(str[i]==letter)
    {
        ans = i;
        return;
    }
    lastOccurrence_RTL(str, letter, i-1, ans);
}

int main()
{
    string str = "aabbccdeddd";
    char letter = 'a';
    int i = str.size()-1;
    int n = str.size();
    int ans = -1;
    lastOccurrence_RTL(str, letter, i, ans);
    cout<<ans;
}