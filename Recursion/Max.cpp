#include<iostream>
#include<limits.h>
using namespace std;

void find_max(int arr[], int n, int i, int& maxi)
{
    //B.C
    if (i>=n)
    {
        return;
    }

    //Processing
    if(arr[i]>maxi)
    {
        maxi = arr[i];
    }
    //R.R
    find_max(arr,n,i+1,maxi);

}
int main()
{
    int arr[] = {10,18,65,9,8};
    int n = 5;
    int i = 0;
    int maxi = INT_MIN;
    find_max(arr,n,i,maxi);
    cout<<"Max element is: "<<maxi;
}