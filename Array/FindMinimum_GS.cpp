#include<iostream>
#include<cmath>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

/*
  Problem recap :
  - One operation: pick two existing elements x, y; append |x - y| to the array.
  - Do exactly K operations. Goal: minimize the final minimum element.

  Key facts used here:
  1) If K == 0 -> no change -> answer is current min.
  2) If any duplicates exist and K >= 1 -> we can do |v - v| = 0 in one step, and
     "burn" remaining steps without increasing the min -> answer = 0.
  3) If K == 1 (no duplicates) -> you can append only one value; the smallest value
     you can append is the smallest adjacent difference after sorting (call it d).
     So answer = min(current_min, d).
  4) If K >= 2 (no duplicates) -> the smallest positive value you can force is the
     GCD of all differences (g). This comes from the invariant:
       gcd(x, y) = gcd(y, |x - y|)
     So all numbers you can ever create are multiples of g; the smallest positive
     multiple is g. Hence answer = min(current_min, g).
*/

int findMinimum(vector<int> arr, int k){
    // Sort so we can (a) read current min quickly and (b) scan adjacent diffs
    sort(arr.begin(),arr.end());
    int minVal = arr[0];

     // Case K == 0: no operations; final min is just the current min.
    if(k==0){
        //no operations to be performed
        return arr[0];
    }

    int diff = INT_MAX;
    // Compute smallest adjacent difference d (also detects duplicates when d == 0).
    for(int i=1;i<arr.size();i++){
        diff = min(diff, arr[i]-arr[i-1]);
    }

     // If we already have duplicates and at least one op to spend, we can create 0.
    if(diff==0) 
    {
        return diff;
    }
    if(k==1){
        return min(diff, minVal); //
    }

    // K >= 2 and no duplicates: compute g = gcd of differences against an anchor.
    // Using arr[0] as anchor is standard; gcd(|a[i] - a[0]|) equals gcd of all pairwise diffs.
    int gcdVal = 0;
    for(int i=1;i<arr.size();i++){
        gcdVal = std::gcd(gcdVal, abs(arr[i]-arr[0])); //arr[0] is the anchor value
    }

     // Final answer when K >= 2: we can (eventually) reach g, but never go below g positively.
    return min(gcdVal, minVal);
        
}
int main(){
    vector<int> arr = {4,4,7};
    int findMinmum = findMinimum(arr, 3);
    cout<<"Minimum value after operations: "<<findMinmum<<endl;
    return 0;
}

/* Time Complexity: 
O(n log n) for the sort
Scan for smallest adjacent diff d: one pass → O(n).
GCD fold over differences: n-1 calls to std::gcd. So this step is O(n log M) (with M ≈ max |a[i] - a[0]|).
Overall, O(n log n + n + n log M) = O(n log n)

Space Complexity: O(1)  (in-place sort).
*/