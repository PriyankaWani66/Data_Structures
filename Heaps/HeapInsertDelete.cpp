//Max heap implementation in C++
#include<iostream>
#include<vector>
using namespace std;

class Heap{
    public:
    vector<int> arr;
    int size;

    Heap()
    {
        arr.push_back(-1); // To make the array 1-based index
        size = 0;
    }

    // Time Complexity for each insert: O(log n) 
    //Inserting n elements will take O(n log n)
    // Space Complexity: O(1) because its iterative and not recursive(heapify)
    void insert(int value) {
        // Insert value at the end
        size++;
        arr.push_back(value);

        int index = size;
        // Place the value at the correct position //indexing is 1-based
        while(index>1) {
            int parentIndex = index / 2;
            if(arr[index] > arr[parentIndex]){
                swap(arr[index],arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }

    // Time Complexity for delete: O(log n)
    //Space Complexity: O(1) because its iterative and not recursive(heapify)
    int deleteNode(){
        //heap always delete root node
        int ans = arr[1];
        arr[1] = arr[size];
        arr.pop_back(); // Remove the last element
        size--;

        int index = 1;
        while(index<size)
        {
            int left = 2*index;
            int right = 2*index+1;

            int largest = index;

            if(left<=size && arr[largest]<arr[left]){
                largest=left;
            }
            if(right<=size && arr[largest]<arr[right]){
                largest=right;
            }

            if(largest!=index){
                swap(arr[index],arr[largest]);
                index=largest;
            }
            else{
                break; // Value is at correct position
            }
        }
        return ans;
    }
};


int main(){
    Heap h; //create a heap object
    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(100);
    cout<< "Printing the heap: " << endl;
    for(int i=1;i<=h.size;i++)
    {
        cout<<h.arr[i]<<" ";
    }
    cout << endl;
    int ans = h.deleteNode();
    cout<< "Deleted element: " << ans << endl;
    cout<< "Printing the heap after calling deletion: " << endl;
    for(int i=1;i<=h.size;i++)
    {
        cout<<h.arr[i]<<" ";
    }
}