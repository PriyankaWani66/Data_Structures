#include<iostream>
#include<vector>
using namespace std;

bool ifMove(int rows, int cols,int maze[][4], vector<vector <bool>>& visited,string output, vector<string>& paths, int i, int j)
{
    if((i>=0 && i<rows && j>=0 && j<cols) && (visited[i][j]==false) && maze[i][j]==1)
    {
        return true;
    }
    return false;
}

void findPaths(int rows, int cols,int maze[][4], vector<vector <bool>>& visited,string output, vector<string>& paths, int i, int j,int* dx,int* dy,char* dir)
{
    //B.C - if destination == maze destination
    if(i==rows-1 && j==cols-1) 
    {
        //destination found
        paths.push_back(output);
        return;
    }

    //Processing
    for(int k=0;k<4;k++)
    {
        int new_i = i+dx[k];
        int new_j = j+dy[k];
        if (ifMove(rows, cols, maze, visited, output, paths, new_i, new_j))
        {
            visited[new_i][new_j] = true;
            findPaths(rows, cols, maze, visited, output+dir[k], paths, new_i, new_j,dx,dy,dir);
            visited[new_i][new_j] = false; //backtrack
        }
    }



}
int main()
{
    //maze
    int rows = 4;
    int cols = 4;
    int maze[4][4] = { {1,0,0,0}, 
                 {1,1,0, 1},
                 {1,1,0,0},
                 {0,1,1,1}};
    //or 
    //vector<int> maze = {{1,0,0},{1,0,1},{1,1,1},{0,1,1}};

    //visited array => initialize with false
    vector<vector <bool>> visited(rows,vector<bool> (cols,false));
    visited[0][0] = true; //source is true
    string output = "";
    vector<string> paths;

    int dx[] = {1,0,0,-1};
    int dy[] = {0,-1,1,0};
    char dir[] = {'D','L','R','U'};
    //if source itself is 0
    if(maze[0][0] == 0)
    {
        cout<<"No path exists"<<endl;
    }

    findPaths(rows, cols, maze, visited, output, paths, 0, 0,dx,dy,dir);

    cout<<"printing paths"<<endl;
    for(auto i: paths)
    {
        cout<<i<<" ";
    }
    if(paths.size()==0)
    {
        cout<<"No path found"<<endl;
    }


}