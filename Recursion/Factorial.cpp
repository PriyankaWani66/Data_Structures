#include<iostream>
using namespace std;

int fact(int n)
{
    //B.C
    if(n==0)
    {
        return 1;
    }
    
    // Recursive Case: n! = n * (n-1)!
    return n*fact(n-1);
}
int main()
{
    cout<<"Enter n: "<<endl;
    int n;
    cin>>n;

    int ans = fact(n);
    cout<<"Factorial is : "<<ans<<endl;
}