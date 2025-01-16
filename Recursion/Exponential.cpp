#include<iostream>
using namespace std;

int exp(int n)
{
    //B.C
    if(n==0)
    {
        return 1;
    }
    
    // Recursive Case: 2^n = 2 * 2^(n-1)
    return 2*exp(n-1);
}
int main()
{
    cout<<"Enter n: "<<endl;
    int n;
    cin>>n;

    int ans = exp(n);
    cout<<"2^n is : "<<ans<<endl;
}