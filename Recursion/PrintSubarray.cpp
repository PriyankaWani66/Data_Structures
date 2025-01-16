#include<iostream>
#include<vector>
using namespace std;

void allOccurrences(vector<int> &nums, int start, int end)
{
    //B.C
    if(end==nums.size())
    {
        return;
    }

    //Processing
    for(int i=start;i<=end;i++) 
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    //Recursion
    allOccurrences(nums,start,end+1);
}
void printSubarry(vector<int> &nums)
{
    for(int start = 0; start<nums.size();start++)
    {
        int end = start;
        allOccurrences(nums, start, end);

    }
}
int main()
{
    vector<int> nums {1,2,3,4,5};
    printSubarry(nums);
}