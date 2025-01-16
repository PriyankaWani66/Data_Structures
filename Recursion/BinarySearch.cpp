#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr, int s, int e, int target)
{
    int mid = s + (e-s)/2;

    //B.C
    if(s>e)
    {
        return -1;
    }

    //checking condition
    if(arr[mid]==target)
    {
        return mid;
    }
    if(arr[mid]>target)
    {
        return binarySearch(arr, s, mid-1, target);
    }
    else
    {
        return binarySearch(arr,mid+1, e, target);
    }

}
int main()
{
  vector<int> arr {10,20,30,40,50};
  int target = 10;
  int s = 0;
  int e = arr.size()-1;
  int ans = binarySearch(arr, s, e, target);  
  cout<<ans;
}