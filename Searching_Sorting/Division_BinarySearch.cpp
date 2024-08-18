#include<iostream>
using namespace std;

int solveDivision(int dividend,int divisor)
{
    int s= 0;
    int e = abs(dividend);
    int mid = s + (e-s)/2;
    int ans = 0;

    while(s<=e)
    {
        if(abs(mid*divisor)==abs(dividend))
        {
            ans = mid;
            break;
        }
        else if(abs(mid*abs(divisor)) < abs(dividend))
        {
            ans = mid;
            s = mid+1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    if((dividend<0 && divisor<0)||(dividend>0 && divisor>0))
    {
        return ans;
    }
    else
    {
        return -ans;
    }
    
}

int main()
{
    int dividend = 36;
    int divisor = 6;
    int quotient = solveDivision(dividend,divisor);
    cout<<quotient;
}