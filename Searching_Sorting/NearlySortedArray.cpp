#include<vector>
#include<iostream>
using namespace std;

int nearlySortedArray(vector<int> arr, int target)
{
    int s = 0;
    int e = arr.size()-1;
    int mid = s+(e-s)/2;

    while (s<=e)
    {
        if(target == arr[mid])
        {
            return mid;
        }
        else if(mid-1>=0 && target == arr[mid-1])
        {
            return mid-1;
        }
        else if(mid+1<arr.size() && target == arr[mid+1])
        {
            return mid+1;
        }
        else if(target>arr[mid])
        {
            s =  mid+2;
        }
        else
        {
            e = mid - 2;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}
int main()
{
    vector<int> arr = {10,3,40,20,50,80,70};
    int target = 30;

    int index = nearlySortedArray(arr,target);
    cout<<"Index of element is: "<<index<<endl;
    
}