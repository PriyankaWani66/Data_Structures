#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
bool isPossibleSolution(int arr[], int n, int k, int mid)
{
    long long allocations = 1;
    long long timeSum = 0;
    for(int i = 0; i<n; i++)
    {
        if(arr[i]>mid)
        {
            return false;
        }
        if(arr[i]+timeSum > mid)
        {
            allocations++;
            timeSum = arr[i];
            if(allocations > k)
            {
                return false;
            }
        }
        else
        {
            timeSum+=arr[i];
        }
    }
    return true;
}
int main()
{
    int arr[] = {5,10,30,20,15};
    int n = 100000;
    int k = 10000;
    long long ans = -1;
    long long s = 0;
    long long e = accumulate(arr,arr+n,0LL);

    long long mid=s+(e-s)/2;
    while(s<=e)
    {
        if(isPossibleSolution(arr, n, k,mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s+(e-s)/2;
    }
    cout<<ans;
}



