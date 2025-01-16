#include<iostream>
#include<vector>
using namespace std;

void isSubsequence(string& str, string output, int size, int i)
{
    //B.C
    if(i>size)
    {
        cout<<output<<endl;
        return;
    }

    //Exclude
    isSubsequence(str, output, size, i+1);

    //Include
    output = output+str[i];
    isSubsequence(str, output, size, i+1);
}
int main()
{
    string str = "abc";
    string output = "";
    int i = 0;
    int size = str.length()-1;
    isSubsequence(str, output, size, i);
}