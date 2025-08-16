//max heap implementation , 1 based indexing
#include<iostream>
using namespace std;

//T.C is O(logn) for heapify
//S.C is O(logn) for heapify because of recursion stack
void heapify(int arr[], int n, int i){
    int index = i;
    int left = 2*i;
    int right = 2*i+1;

    int largest = index;
    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }

    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=index){
        swap(arr[largest],arr[index]);
        index=largest;
        heapify(arr,n,index);
    }
}

//T.C is O(n) for building heap
//S.C is O(logn) for building heap because of recursion stack
void buildHeap(int arr[],int n){
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);  //In a CBT, (n/2 + 1) to n are leaf nodes, so we start from n/2
    }
}

//T.C is O(nlogn) for heap sort
//S.C is O(logn) for heap sort because of recursion stack
void heapSort(int arr[], int n){
    while(n!=1){
        swap(arr[1],arr[n]);
        n--;
        heapify(arr,n,1);
    }
}

//Total T.C for heap sort is O(nlogn) because we are calling heapify n times and each heapify takes O(logn) time.
int main(){
    int arr[] = {-1,12, 56, 43, 6, 78, 87, 5, 44, 3, 23, 32};
    int n = 11;
    buildHeap(arr,n);

    cout << "printing the heap "<< endl;
    for(int i=0; i<=n; i++) {
            cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr,n);
    cout << endl << "printing the heap after sorting "<< endl;
    for(int i=0; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}