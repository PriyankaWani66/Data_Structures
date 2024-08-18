#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
bool isPossibleSolution(vector<int>arr, int M, int N, int sol)
{
    int pageSum = 0;
    int allocations = 1;
    for(int i=0;i<N;i++)
    {
        if(arr[i]>sol)
        {
            return false;
        }
        if(pageSum+arr[i]>sol)
        {
            allocations++;
            pageSum=arr[i];
            if(allocations>M)
            {
                return false;
            }
        }
        else
        {
            pageSum+=arr[i];
        }
    }
    return true;
}
int main()
{
    vector<int> arr = {12,34,67,90};
    int N = 4;
    int M = 2;
    int s = 0;
    int e = accumulate(arr.begin(),arr.end(),0);
    int mid = 0;
    int ans = -1;
    if(M>N)
    {
        return ans;
    }
    while(s<=e)
    {
        mid = s+(e-s)/2;
        if(isPossibleSolution(arr,M,N,mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    cout<<ans;
    
    
}
