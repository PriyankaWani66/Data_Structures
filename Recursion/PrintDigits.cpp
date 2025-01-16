#include<iostream>
using namespace std;

void printDigits(int n)
{
    //B.C
    if(n==0)
    {
        return;
    }
    
    //R.R
    int new_num = n/10;
    printDigits(new_num);

    //processing
    int digit = n%10;
    cout<<digit<<" ";
   
}

int main()
{
    int n = 647;
    printDigits(n);
}