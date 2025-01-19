//Missing elements from an array with Duplicates - method 1) Swapping

#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector <int> arr = {1,3,3,3,4};
    int i= 0;
    int n = arr.size();
    while(i<n)
    {
        int index = arr[i] - 1;
        if(arr[i]!=(arr[index]))
        {
            swap(arr[i],(arr[index]));
        } 
        else
        {
            i++;
        }
    }
    


    for(int i=0; i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=0; i<arr.size();i++)
    {
        if(arr[i]!=i+1)
        {
            cout<<i+1<<" ";
        }
    }
    
    return 0;
}