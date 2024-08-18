#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int binarySearch(vector<int> nums, int start, int num)
{
    int end = nums.size()-1;
    int mid = start+(end - start)/2;
    while(start<=end)
    {
        if(num == nums[mid])
        {
            return mid;
        }
        else if(num<nums[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start+(end - start)/2;
    }
    return -1;
    
}
int main(){
    vector<int> nums = {1,3,1,4,5};
    set<pair<int, int>> ans;
    int k = 2;
    sort(nums.begin(),nums.end());
    for(int i = 0; i<nums.size(); i++)
    {
        if(binarySearch(nums, i+1, k+nums[i]) != -1)
            {
                ans.insert({nums[i], k+nums[i]});
            }
    }
    
    cout<<ans.size()<<endl;
    for (auto pair : ans) {
        cout << pair.first << " " << pair.second << endl;
    }

}