#include<iostream>
#include<vector>
using namespace std;


void wave_columnwise(vector<vector<int>> v, int row, int col){
    for(int i=0; i<col;i++)
    {
        if((i & 1) == 0)
        {
            for(int j=0;j<row;j++)
            {
                cout<<v[j][i]<<" ";
            }
        }
        else
        {
            for(int j = row-1;j>=0;j--)
            {
                cout<<v[j][i]<<" ";
            }
        }
    }
}


void wave_rowwise(vector<vector<int>> v, int row, int col){
    for(int i=0; i<row;i++)
    {
        if((i & 1) == 0)
        {
            for(int j=0;j<col;j++)
            {
                cout<<v[i][j]<<" ";
            }
        }
        else
        {
            for(int j = col-1;j>=0;j--)
            {
                cout<<v[i][j]<<" ";
            }
        }
    }
}


int main()
{   
    vector<vector<int>> v  = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int row = v.size();
    int col = v[0].size();
    wave_columnwise(v, row, col);
    cout<<endl;
    wave_rowwise(v,row,col);
    

    return 0;
}