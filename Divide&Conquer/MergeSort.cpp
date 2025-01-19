#include<iostream>
using namespace std;

void mergeAndsort(int* arr,int s,int e)
{
    int mid = (s+e)/2;

    //get length of both : left and right array
    int len1 = mid-s+1;
    int len2 = e-mid;

    //create both left and right array
    int* left = new int[len1];
    int* right = new int[len2];

    //copy the values of the whole array into left and right to sort it and then merge it 
    int k = s; //start index
    for(int i=0;i<len1;i++)
    {
        left[i] = arr[k];
        k++;
    }

    k = mid+1; //start index
    for(int i=0;i<len2;i++)
    {
        right[i] = arr[k];
        k++;
    }

    //compare left and right array and then copy it to the main array
    int leftIndex = 0;
    int rightIndex = 0;
    int mainIndex = s;

    while(leftIndex<len1 && rightIndex<len2)
    {
        if(left[leftIndex]<right[rightIndex])
        {
            arr[mainIndex++] = left[leftIndex++];
        }
        else
        {
            arr[mainIndex++] = right[rightIndex++];
        }
    }

    //copy remaining elements if one array is over
    while (leftIndex<len1)
    {
        arr[mainIndex++] = left[leftIndex++];
    }

    while (rightIndex<len2)
    {
        arr[mainIndex++] = right[rightIndex++];
    }
    


}

void mergeSort(int* arr, int s, int e)
{
    //B.C ==> to divide until we get a single element and then return to the previous element
    if(s>=e)
    {
        return;
    }

    int mid = (s+e)/2;

    //divide left array using recursion until we get a single element
    mergeSort(arr,s,mid);

    //divide right array using recursion until we get a single element
    mergeSort(arr,mid+1,e);

    //sort and merge the final array
    mergeAndsort(arr,s,e);
}
int main()
{
    int arr[] = {2,1,3,8,6,9};
    int size = 6;
    int s = 0;
    int e = size-1;
    mergeSort(arr,s,e);

    //print sorted array
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}