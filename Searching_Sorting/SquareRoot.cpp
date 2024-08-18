#include<iostream>
using namespace std;
int findSqrt(int n)
{
    int s = 0;
    int e = n;
    int mid =  s + (e-s)/2;
    int ans = -1;
    while(s<=e)
    {
        if(mid*mid ==n)
        {
            return mid;
        }
        else if(mid*mid<n)
        {
            ans = mid;
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
        mid =  s + (e-s)/2;
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the number:"<<" ";
    cin>>n;
    cout<<endl;
    int ans = findSqrt(n);

    //precision
    double step = 0.1;
    double finalAns = ans;
    int precision;
    cout<<"Enter the precision: ";
    cin>>precision;
    for(int i =0;i<precision;i++)
    {
        for(double j=finalAns; j*j<=n;j=j+step)
        {
            finalAns = j;
        }
        step = step/10;
    }
    cout<<"Square root of the number is: "<<finalAns;
}