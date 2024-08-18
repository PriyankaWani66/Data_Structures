#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr = {10,9,2,6,8,1};
    int n = arr.size();
    for(int round = 1; round<n; round++)
    {
        int swappedCount = 0;
        for(int j = 0; j<n-round; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swappedCount++;
            }
        }
        if(swappedCount==0)
        {
            break;
        }
    }

    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}