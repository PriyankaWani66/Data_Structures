#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossibleSolution(vector <int> cookRanks, int nC, int nP, int mid)
{
    int noOfPratas = 0;
    for(int i = 0; i<cookRanks.size();i++)
    {
        int PrataAllocation = 1;
        int timeTaken = 0;
        while(true)
        {
            if(timeTaken + PrataAllocation*cookRanks[i] <= mid)
            {
                noOfPratas++;
                timeTaken += PrataAllocation*cookRanks[i];
                PrataAllocation++;
            }
            else
            {
                break;
            }
        }
        if(noOfPratas>=nP)
        {
            return true;
        } 
    }
    return false;
}

int minTimeRequiredForPrata(vector <int> cookRanks, int nC, int nP)
{
    int s = 0;
    int highRank = *max_element(cookRanks.begin(),cookRanks.end());
    int e =  highRank * (nP * (nP+1)/2);
    int ans = -1;
    while (s<=e)
    {
        int mid = s+(e-s)/2;
        if (isPossibleSolution(cookRanks, nC, nP, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    } 
    return ans;   
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nP;
        cin>>nP;
        int nC;
        cin>>nC;
        vector <int> cookRanks;
        while(nC--)
        {
            int rank;
            cin>>rank;
            cookRanks.push_back(rank);
        }
        cout<<minTimeRequiredForPrata(cookRanks, nC, nP)<<endl;

    }

    return 0;
}