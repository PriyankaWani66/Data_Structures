#include<iostream>
#include<vector>
using namespace std;

int PeakElement(vector<int> arr)
{
    int e = arr.size() - 1;
    int s = 0;
    int mid = s + (e-s)/2;
    while(s<e)
    {
        if(arr[mid]<arr[mid+1])
        {
            s = mid+1;
        }
        
        else 
        {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}
int main()
{
    vector<int> arr = {0,10,5,2,1};
    int number = PeakElement(arr);
    cout<<"Peak index is: "<<number;

}