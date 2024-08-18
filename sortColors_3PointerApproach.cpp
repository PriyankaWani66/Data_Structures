#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector<int> nums = {1,1,0,2,0,1,2,0,1};

    int l = 0;
    int m = 0;
    int h = nums.size()-1;

    while(m<=h)
    {
        if(nums[m]==0)
        {
            swap(nums[m],nums[l]);
            m++;
            l++;
        }
        else if(nums[m]==1)
        {
            m++;
        }
        else{
            swap(nums[m],nums[h]);
            h--;
        }
    }
    for(int i=0; i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;

    
}