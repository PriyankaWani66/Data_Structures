#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int>& arr,int& n, int i)
{
    //B.C
    if(i==n-1)
    {
        return true;
    }

    //checking condition
    if(arr[i+1]<arr[i])
    {
        return false;
    }
    isSorted(arr,n,i+1);
}
int main()
{
    vector<int> arr = {10,20,30,40,50};
    int n = arr.size();
    int i = 0;
    if(isSorted(arr,n,i))
    {
        cout<<"array is sorted"<<endl;
    }
    else
    {
        cout<<"array is not sorted"<<endl;
    }

}