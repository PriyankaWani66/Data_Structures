#include<iostream>
#include<queue>
using namespace std;

//approach 1: to find kth smallest/largest element using sorting. T.C is O(nlogn) and S.C is O(1)

//approach 2: to find kth smallest element using min heap. T.C is O(n) and S.C is O(n) to store all elements and then retrieve the smallest element i.e, top of min heap.
//to find kth largest element using max heap. T.C is O(n) and S.C is O(n) to store all elements and then retrieve the largest element i.e, top of max heap.

//approach 3: to find kth smalles element using min heap. T.C is O(n lok K) and S.C is O(k) to store k elements and then compare the top of min heap with the current element. If the current element is smaller than the top of min heap, then pop the top and push the current element.
//to find kth largest element using max heap. T.C is O(n log K) and S.C is O(k) to store k elements and then compare the top of max heap with the current element. If the current element is larger than the top of max heap, then pop the top and push the current element.
//Log k to insert K elements in heap.
int kthSmallest(int arr[], int n, int k) {
    priority_queue<int> pq;

    //create a max heap of size k
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i=k;i<n;i++){
        int element = arr[i];
        if(element<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int ans = pq.top();
    return ans;
}

int kthGreatest(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    //create a min heap of size k
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i=k;i<n;i++){
        int element = arr[i];
        if(element>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int ans = pq.top();
    return ans;
}

int main(){
    int arr[] = {50,10,30,40,1};
    int n = 5;
    int k = 5;
    int smallest = kthSmallest(arr,n,k);
    cout<<"smallest element is: "<<smallest<<endl;
    int largest = kthGreatest(arr,n,k);
    cout<<"largest element is: "<<largest<<endl;
    return 0;
}