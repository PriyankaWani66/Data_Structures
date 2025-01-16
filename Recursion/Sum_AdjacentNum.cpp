#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

void MaxSum(vector<int>& arr, int i, int& maxi, int sum)
{
    //B.C
    if(i>=arr.size())
    {
        maxi = max(sum, maxi);
        return;
    }

    //include
    MaxSum(arr, i+2, maxi, sum+arr[i]);

    //exclude
    MaxSum(arr, i+1, maxi, sum);
}
int main()
{
    vector<int> arr {1,2,3,1,3,5,8,1,9};
    int i = 0;
    int size = arr.size();
    int maxi = INT_MIN;
    int sum = 0;
    MaxSum(arr,i, maxi, sum);
    cout<<maxi;
}