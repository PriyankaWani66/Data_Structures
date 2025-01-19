#include<math.h>
#include<iostream>
#include<vector>
using namespace std;

vector<bool> Sieve(int n)
{
   vector<bool> sieve(n+1,true);
   sieve[0]=sieve[1]=false;
   for(int i=2;i*i<=n;i++)
   {
    if(sieve[i]==true)
    {
        int j = i*i;
        while(j<=n)
        {
            sieve[j]=false;
            j+=i;
        }
    }
   } 
   return sieve;
}

vector<bool> segSieve(int L, int R)
{
    //get prime arrays using normal sieve function
    vector<bool> sieve = Sieve(sqrt(R));
    vector<int> basePrimes;
    for(int i=0;i<sieve.size();i++)
    {
        if(sieve[i])
        {
            basePrimes.push_back(i);
        }
    }

    vector<bool> seg(R-L+1, true);
    if(L==1 || L==0)
    {
        seg[L]=false;
    }

    for(auto prime:basePrimes)
    {
        int first_mul = (L/prime)*prime;
        if(first_mul<L)
        {
            first_mul+=prime;
        }
        int j = max(first_mul,prime*prime);
        while(j<=R)
        {
            seg[j-L]=false;
            j+=prime;
        }
        
        
    }
    return seg;
}

int main()
{
    int L = 110;
    int R = 130;
    vector<bool> segmentedSieve = segSieve(L,R);
    for(int i=0;i<segmentedSieve.size();i++)
    {
        if(segmentedSieve[i])
        {
            cout<<i+L<<" ";
        }
    }
}