#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

bool possibleSolution(long long int mid,long long int m,vector<long long int> heights)
{
    long long int heightSum=0;
    for(long long int i = 0; i<heights.size();i++)
    {
        if(heights[i]-mid>0)
        {
            heightSum+= heights[i]-mid;
        }
        
    }
    if(heightSum>=m)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
long long int maxHeight(vector<long long int> heights,long long int m)
{
    long long int ans = -1;
    long long int s = 0;
    long long int e = *max_element(heights.begin(),heights.end());
    while(s<=e)
    {
        long long int mid = s+(e-s)/2;
        if(possibleSolution(mid,m,heights))
        {
            ans = mid;
            s =  mid + 1;

        }
        else
        {
            e = mid-1;
        }
    }
    return ans;
}
int main()
{
    long long int n;
    long long int m;
    vector<long long int> heights;
    cin>>n>>m;
    while(n--)
    {
        long long int height;
        cin>>height;
        heights.push_back(height);
    }

    cout<<maxHeight(heights,m)<<endl;
    return 0;
}