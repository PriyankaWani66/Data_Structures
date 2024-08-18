#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int> vec)
{
    int s = 0;
    int e = vec.size()-1;
    int mid = s+(e-s)/2;

    while(s<=e)
    {
        if(mid+1<vec.size() && vec[mid]>vec[mid+1])
        {
            return mid;
        }
        if (mid-1>=0 && vec[mid-1]>vec[mid])
        {
            return mid-1;
        }
        else if(vec[s]>=vec[mid])
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }
}

int main()
{
    vector<int> vec = {2,3,4,5,6,7,1};

    int ans = findPivot(vec);
    cout<<"Index of pivot element is: "<<ans;
    return 0;
}