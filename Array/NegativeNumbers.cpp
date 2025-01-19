#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector<int> arr = {-1,-2,-4,-3};
    int l=0;
    int h = arr.size()-1;

    while(l<h)
    {
        if(arr[l]>0)
        {
            swap(arr[l],arr[h]);
            h--;
        }
        else
        {
            l++;
        }
    }
    for(int i=0; i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}