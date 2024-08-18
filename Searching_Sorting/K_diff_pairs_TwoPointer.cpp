#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    vector<int> nums = {1,3,1,4,5};
    set<pair<int, int>> ans;
    int i = 0;
    int j = 1;
    int k = 2;
    sort(nums.begin(),nums.end());
    while (j<nums.size())
    {
        int diff = nums[j]-nums[i];
        if(diff == k)
        { 
            ans.insert({nums[i],nums[j]});
            //cout<<nums[i]<<" "<<nums[j]<<endl;
            i++;
            j++;
        }
        else if(diff > k)
        {
            i++;
        }
        else
        {
            j++;
        }
        if(i==j)
        {
            j++;
        }
    }
    cout<<ans.size()<<endl;
    for (auto pair : ans) {
        cout << pair.first << " " << pair.second << endl;
    }
    
}