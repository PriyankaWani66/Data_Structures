#include<vector>
#include<iostream>
using namespace std;

int main()
{
    int ans = -1;
    vector<int> arr = {2,4,2,3,1};
    while(arr[0]!=arr[arr[0]])
    {
        swap(arr[0],arr[arr[0]]);
    }
    ans = arr[0];
        
    
    cout<<ans;
    return ans;
}