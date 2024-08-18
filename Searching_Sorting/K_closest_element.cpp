#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

//time complexity - O(n log n); Space complexity - O(n) because of the make_pair
void differenceSort(vector<int> arr, int k, int x)
{
    vector<pair<int, int>> diffPairs;
    for(int value: arr)
    {
        diffPairs.push_back(make_pair(abs(value - x),value));
    }
    sort(diffPairs.begin(),diffPairs.end());
    vector<int>result;
    for(int i =0;i<k;i++)
    {
        result.push_back(diffPairs[i].second);
    }
    cout<<"Output using sorting based on the difference:"<<endl;
    for(int i =0; i<k;i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
}

//Time complexity : O(n) ; Space complexity - O(1)
int TwoPointer(vector<int> arr, int k, int x)
{
    int l = 0;
    int h = arr.size()-1;
    while(h-l>=k)
    {
        if(x-arr[l]>arr[h]-x)
        {
            l++;
        }
        else
        {
            h--;
        }
    }
    cout<<"Output using Two pointer approach: "<<endl;
    for(int i = l; i<=h;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr = {12,16,22,30,35,39,42,45,48,50,53,55,56};
    int k = 4;
    int x = 35;
    differenceSort(arr,k,x);
    TwoPointer(arr,k,x);
}