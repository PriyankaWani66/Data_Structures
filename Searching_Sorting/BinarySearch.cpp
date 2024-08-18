#include<iostream>
#include<vector>
using namespace std;

int indexOfBinaryAlgorithm(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end-start)/2;
    while(start <= end)
    {
        if(arr[mid] == target)
        {
            return mid;
        }
        else if (target<arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int main()
{
    vector<int> arr = {2,4,6,8,10,12,14,16};
    int target = 2;
    int index = indexOfBinaryAlgorithm(arr, target);
    if(index == -1)
    {
        cout<<"number not found";
    }
    else{
        cout<<"number found at index: "<<index;
    }

    return 0;
}