#include<iostream>
#include<vector>
using namespace std;

int searchRotatedSortedArray(vector<int> arr, int target)
{
    int s = 0;
    int e = arr.size()-1;
    int mid = s + (e-s)/2;

    while(s<=e)
    {
        if(target == arr[mid])
        {
            return mid;
        }
        // Check if the left half is sorted
        if (arr[s] <= arr[mid]) 
        {
            // Check if the target is in the left half
            if (arr[s] <= target && target < arr[mid]) 
            {
                e = mid - 1;
            } 
            else 
            {
                s = mid + 1;
            }
        } 
        else 
        { // The right half must be sorted
            // Check if the target is in the right half
            if (arr[mid] < target && target <= arr[e]) 
            {
                s = mid + 1;
            } 
            else 
            {
                e = mid - 1;
            }
        }
        mid = s+(e-s)/2;
    }
    return -1;
}
int main()
{
    vector<int> arr = {4};
    int target = 4;
    int ans = searchRotatedSortedArray(arr,target);
    cout<<ans;
    return 0;
}