#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Why MIN-HEAP?
//- We’re merging k sorted arrays.
//- At any time, we only need the smallest among the k current “heads”.
//- A MIN-heap keeps that smallest element at the top so we can take it next.
//We use max heap for merging arrays in descending order.


// Why custom comparator?
// - std::priority_queue is a MAX-heap by default (largest on top).
// - We flip the order so the smallest value rises to the top.
// - For pointers:   return a->data > b->data;  // smaller data gets higher priority
// - For by-value:   return a.val   > b.val;

class info {
    public:
        int data;
        int row;
        int col;

    info(int val, int r, int c) {
        data = val;
        row = r;
        col = c;
    }
};

//custom comparator for priority queue
class compare{
    public:
    bool operator()(info* a, info* b){
        return a->data > b->data; // smaller data gets higher priority
    }
};
vector<int> merge_k_sorted_arrays(vector<int> ans, int arr[][4], int k, int n)
{
    priority_queue<info*, vector<info*>, compare> minHeap;

    //insert first element of each array into the min heap
    for(int i=0;i<k;i++){
        info* temp = new info(arr[i][0],i,0);
        minHeap.push(temp);
    }

    while(!minHeap.empty()){
        info* temp = minHeap.top();
        int topElement = temp->data;
        int topRow = temp->row;
        int topCol = temp->col;

        minHeap.pop();

        ans.push_back(topElement);

        //if there is a next element in the same row, insert it into the min heap
        if(topCol+1<n){
            info* newInfo = new info(arr[topRow][topCol+1],topRow, topCol+1);
            minHeap.push(newInfo);
        }
    }
    return ans;
}
int main(){
    int arr[][4] = { {2,4,6,8},
                    {1,3,5,7},
                    {0,9,10,11}
                    };
    int k = 3; // number of arrays
    int n = 4; // size of each array
    vector<int> ans; // to store the merged result
    ans = merge_k_sorted_arrays(ans, arr, k, n);
    for(auto i: ans) {
        cout << i << " ";
    }
    
    return 0;
}

/*
Time Complexity (min-heap k-way merge)
- Let k = number of arrays, each length n (total N = k*n elements).
- Each element is pushed once and popped once from the heap.
- Heap ops are O(log k).
=> Total time: O(N log k)  [= O(k*n*log k)]

Space Complexity
- Heap holds at most k items at any time => O(k).
- Output vector stores all N elements => O(N) (inevitable result storage).
- Aux (pointers/structs/comparator) is O(1) extra.
=> Aux space: O(k)  (excluding the output)
=> Total space incl. result: O(N + k)

Notes
- Same asymptotics whether storing heap entries by pointer or by value.
- Best/avg/worst are all O(N log k) (heap cost dominates).
*/
