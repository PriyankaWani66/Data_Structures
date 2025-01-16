#include<iostream>
using namespace std;

void reverseString(int start, int end, string &str)
{
    //B.C
    if(start>=end)
    {
        return;
    }

    //processing
    swap(str[start],str[end]);

    //Recursion
    reverseString(start+1, end-1, str);
}
int main()
{
    string str = "priyanka";
    int start = 0;
    int end = str.size()-1;
    reverseString(start, end, str);
    cout<<str;
}