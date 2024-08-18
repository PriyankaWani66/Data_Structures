#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,10};
    int s = 0;
    int e = arr.size()-1;
    int mid = s + ((e-s)/2);

    while(s<=e)
    {
        if(mid+1 == arr[mid])
        {
            s = mid+1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + ((e-s)/2);
    }
    cout<<s+1;
    return 0;
}