#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector<int> arr = {1,3,4,2,2};
    int ans = 0;
    for(int i=0; i<arr.size();i++)
    {
        int index = abs(arr[i]);
        if(arr[index]<0)
        {
            ans = abs(arr[i]);
        }
        arr[index] = arr[index]*-1;
    }
    cout<<ans;
    return ans;
}