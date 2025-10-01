/*
Max Team Size with Lower/Higher Skill Bounds

Given:
Two arrays of length n:

lower[i] — max position index t they can handle from the left (needs at least t weaker before them).

higher[i] — max from the right they can handle (needs at least k−1−t stronger after them).

Goal:
Find the largest team size k and an ordering of k distinct candidates at positions t = 0..k−1 such that for each seated candidate i at position t:

lower[i] ≥ t           // can tolerate t weaker before
higher[i] ≥ (k−1−t)    // can tolerate k−1−t stronger after


Key property (monotonicity):
If size k is feasible, then any size ≤ k is also feasible ⇒ enables binary search on k in [0..n].

Feasibility check (greedy for a fixed k):

Sort candidates by lower asc, tie-break higher desc.

t = 0. Scan the sorted list:

If lower[i] ≥ t and higher[i] ≥ (k−1−t), seat them and do t++.

Success if t == k; else fail.

Tie-break higher desc preserves future flexibility and makes the one-pass greedy correct.

Algorithm:
Binary search k in [0..n]; for each k, run the greedy feasibility above.

Time: O(n log n) (sort once) + O(n log n) for checks ⇒ overall O(n log n).

Space: O(1) extra (besides storing the copy/sorted array).

Brute force (for validation/small n):
Backtracking assign positions t=0..k−1, trying any unused i that fits; or bitmask DP. Exponential.

Edge cases & pitfalls:

Off-by-one: use (k−1−t) not (k−t).

Reset t on each feasibility call.

All zeros → answer is min(1, n).

Sorting order matters; without it, the one-pass greedy can fail.

Mini example:
lower=[0,1,2,0], higher=[2,1,0,1] → sorted pairs: (0,2),(0,1),(1,1),(2,0) ⇒ max k = 3.
*/

1-----
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second > b.second; //higher desc
    }
    return a.first < b.first; //lower asc
}

bool checkFeasibility(vector<pair<int, int>>candidates, int k){ // [0,3],[1,2],[2,1]
    int count = 0; //to check how many we have seated
    for(int i=0; i<candidates.size();i++){
        if(candidates[i].first >= count && candidates[i].second >= (k-1-count)){
            count++;
            if(count == k){
                return true; //seated k candidates
            }
        }
    }
    return false; //couldn't seat k candidates
}

int binarySearch(vector<pair<int, int>>candidates){
    int e = candidates.size(); //[0,n] inclusive because k can be 0 to n
    int s = 0;
    int ans = 0;

    while(s<=e){
        int mid = s+(e-s)/2; // => 0+4/2 = 2
        if(checkFeasibility(candidates,mid)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        
    }
    return ans;
}

int main(){
    vector<int> lower = {0,1,2,3}; 
    vector<int> higher = {3,2,1,0};
    int n = lower.size();

    //to store candidates as (lower, higher) pairs
    vector<pair<int, int>> candidates(n);
    for(int i=0;i<n;i++){
        candidates[i] = {lower[i], higher[i]} ;//[0,3],[1,2],[2,1],[3,0], => 0,1,2,3,3
    }

    //sort by lower asc, tie-break higher desc
    sort(candidates.begin(),candidates.end(),comp);

    int ans = binarySearch(candidates);
    cout<<"Max team size is: "<<ans<<endl;
    return 0;
}