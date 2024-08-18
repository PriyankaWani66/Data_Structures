#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//log(2^(log(m)-1))
int binarySearch(vector<int> arr, int start, int end, int x)
{
    int mid = start + (end-start)/2;
    while(start<=end)
    {
        if(arr[mid]==x)
        {
            return mid;
        }
        else if(arr[mid]>x)
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
int expSearch(vector<int> arr, int x)
{
    int n = arr.size();
    if(arr[0]==x)
    {
        return 0;
    }
    int i = 1;
    while(i<n && arr[i]<=x)
    {
        i*=2;
    }
    return binarySearch(arr, i/2, min(i,n-1), x);
    
}

int main()
{
    vector<int> arr = {3,4,5,6,11,13,14,15,56,70};
    int x = 58;
    int index = expSearch(arr,x);
    if(index == -1)
    {
        cout<<"Not found"<<endl;
    }
    else
    {
        cout<<"Element "<<x<<" found at index: "<<index<<endl;
    }
}