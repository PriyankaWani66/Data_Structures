#include<iostream>
using namespace std;

int findPivot(int* arr, int s, int e)
{
    //select the pivot element, lets consider first element as pivot
    int pivotIndex = s;
    int pivotElement = arr[s];

    //now place the pivotElement at its correct place by counting elements smaller than the pivot Element
    int count = 0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivotElement)
        {
            count++;
        }
    }
    //placing in the correct position
    swap(arr[s],arr[s+count]);
    pivotIndex = s+count;

    //check all the elements left to the pivot are smaller and right to the pivot are greater
    int i = s;
    int j = e;
    while(i<pivotIndex && j>pivotIndex)
    {
        //increment i and j if the elements are in correct position
        while(arr[i]<=pivotElement)
        {
            i++;
        }
        while(arr[j]>pivotElement)
        {
            j--;
        }

        //if the elements are not in correct position swap them
        if(i<pivotIndex && j>pivotIndex)
        {
            swap(arr[i],arr[j]);
        }

    }
    return pivotIndex;

}
void quickSort(int* arr, int s, int e)
{
    //B.C
    if(s>=e)
    {
        return;
    }

    //Processing ==> partition logic which selects pivot and divides the array
    int pivotIndex = findPivot(arr,s,e);

    //recursion for the first half and then the second half without the pivot
    quickSort(arr,s,pivotIndex-1);
    quickSort(arr,pivotIndex+1,e);

}
int main()
{
    int arr[] = {1,6,3,5,9,9,9,3,2,5,6,7,11,1,1,1};
    int size = 16;
    int s = 0;
    int e = size - 1;
    quickSort(arr,s,e);

    //print elements
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}