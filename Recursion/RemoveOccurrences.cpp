//1910. Remove All Occurrences of a Substring ==> Leetcode question

#include<iostream>
using namespace std;

void removeOccurrences(string &str, string &part)
{
    int pos = str.find(part);
    if(pos != string::npos)
    {
        //Processing part
        //we are getting the left string and right string which does not include the occureence and adding it to remove the part
        string left = str.substr(0,pos);
        string right = str.substr(pos+part.size(), str.size()); 
        str = left + right;

        //recursion
        removeOccurrences(str,part);
    }
    else
    {
        //B.C ==> when part is not present in the string anymore
        return;
    }
}
int main()
{
    string str = "daabcbaabcbc";
    string part = "abc";
    removeOccurrences(str,part);
    cout<<str;
}