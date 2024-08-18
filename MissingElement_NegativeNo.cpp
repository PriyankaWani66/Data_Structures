//Missing elements from an array with Duplicates - method 1) Negative indexing

#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector <int> arr = {1,2,3,3,3};
    int index = 0;
    for(int i=0;i<arr.size();i++)
    {
       index = abs(arr[i]);
       if(arr[index-1]>0)
       {
            arr[index-1]  *= -1; 
       }
    }


    for(int i=0; i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<arr.size();i++)
    {
        if(arr[i] > 0)
        {
            cout<<i+1<<" ";
        }
    }
    return 0;
}