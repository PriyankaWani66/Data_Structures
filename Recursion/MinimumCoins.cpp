#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int minimumCoins(vector<int>& arr, int target)
{
    //B.C
    //when this path is considered
    if(target == 0)
    {
        return 0;
    }
    //when this path is ignored
    if(target<0)
    {
        return INT_MAX;
    }

    //for loop ==> to traverse through all the numbers in an array
    int mini = INT_MAX;
    for(int i=0; i<arr.size();i++)
    {
        int ans = minimumCoins(arr,target-arr[i]);
        if(ans != INT_MAX)
        {
            mini = min(mini, ans+1);
            //ans+1 because we took 1 coin to reach target - arr[i]
        }
    }
    return mini;
}
int main()
{
    vector<int> arr {1,2,3};
    int target = 2;
    int ans = minimumCoins(arr,target);
    cout<<ans;
}