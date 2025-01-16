#include<iostream>
using namespace std;

void printarr(int arr[],int n, int i)
{
    //B.C
    if(i>=n)
    {
        return;
    }
    cout<<arr[i]<<" ";

    //recursion
    printarr(arr,n,i+1);

}
int main()
{
    int arr[] = {10,20,30,40,50};
    int n = 5;
    int i = 0;
    printarr(arr, n, i);
}
