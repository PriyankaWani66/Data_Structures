//Graph implementation using Adjacency Matrix - Method 1
//Time Complexity: O(n^2) for space, O(1) for adding an edge

#include<iostream>
#include<vector>
using namespace std;

int main(){
    cout<<"Enter the number of nodes: "<<endl;
    int n;
    cin>>n;

    vector<vector<int>> adj(n,vector<int>(n,0)); // Initialize n x n adjacency matrix with 0s
    cout<<"Enter the number of edges: "<<endl;
    int e;
    cin>>e;

    for(int i=0;i<e;i++){
        int u;
        int v;
        cout<<"Enter edge (u v): "<<endl;
        cin>>u>>v;

        adj[u][v] = 1; // Mark the presence of an edge from u to v
    }

    //printing the adjacency matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}