#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector<int> nums = {2,0,0,1};

    int zeros = 0;
    int ones = 0;
    int twos = 0;

    for (int i=0; i<nums.size(); i++)
    {
        if(nums[i] == 0)
        {
            zeros += 1;
        }
        else if(nums[i] == 1)
        {
            ones += 1;
        }
        else
        {
            twos += 1;
        }
    }

    for(int i=0; i<zeros; i++)
    {
        nums[i] = 0;
    }
    for(int j=zeros; j<zeros+ones; j++)
    {
        nums[j] = 1;
    }
    for(int k=zeros+ones; k<nums.size(); k++)
    {
        nums[k] = 2;
    }

    for(int i=0; i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}