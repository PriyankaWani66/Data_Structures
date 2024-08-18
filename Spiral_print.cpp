#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<vector<int>> v = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    int rows = v.size();
    int cols = v[0].size();
    int startCol = 0;
    int startRow = 0;
    int endRow = rows-1;
    int endCol = cols-1;
    int elements = rows*cols;
    int count = 0;

    while(count<elements)
    {
        //print start row
        for(int i=startCol;i<=endCol && count<elements;i++)
        {
            cout<<v[startRow][i]<<" ";
            count++;
        }
        startRow++;

        //print end col
        for(int i=startRow;i<=endRow && count<elements;i++)
        {
            cout<<v[i][endCol]<<" ";
            count++;
        }
        endCol--;

        //print end row
        for(int i=endCol;i>=startCol && count<elements;i--)
        {
            cout<<v[endRow][i]<<" ";
            count++;
        }
        endRow--;

        //print start col
        for(int i=endRow;i>=startRow && count<elements;i--)
        {
            cout<<v[i][startCol]<<" ";
            count++;
        }
        startCol++;
    }
}