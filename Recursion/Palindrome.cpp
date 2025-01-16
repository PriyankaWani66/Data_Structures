#include<iostream>
using namespace  std;

bool checkPalindrome(string &str, int s, int e)
{
    //B.C
    if(s>=e)
    {
        return true;
    }

    //Processing
    if(str[s]!=str[e])
    {
        return false;
    }

    //Recursion
    checkPalindrome(str, s+1, e-1);
}
int main()
{
    cout<<"Enter string: ";
    string str = "";
    cin>>str;
    bool ans = checkPalindrome(str, 0, str.size()-1);
    cout<<ans;
} 

