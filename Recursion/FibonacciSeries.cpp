#include<iostream>
using namespace std;

int fib(int n)
{
    //B.C
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }

    //R.R
    return fib(n-1)+fib(n-2);
}
int main()
{
    cout<<"Enter n: "<<endl;
    int n;
    cin>>n;

    int ans = fib(n);
    cout<<"nth term is: "<<ans<<endl;
}