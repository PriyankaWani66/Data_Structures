#include<iostream>
#include<vector>
using namespace std;

bool findTarget(vector<vector <int>> arr, int target)
{
    int row = arr.size();
    int col = arr[0].size();
    int total_elements = row*col;
    int s = 0;
    int e = total_elements - 1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {
        int rowIndex = mid / col;
        int colIndex = mid % col;
        if(arr[rowIndex][colIndex]==target)
        {
            cout<<"Found at: "<<rowIndex<<" "<<colIndex<<endl;
            return true;
        }
        else if(arr[rowIndex][colIndex] < target)
        {
            s = mid+1;;
        }
        else
        {
            e = mid-1;
        }
        mid = s + (e-s)/2;

    }
    return false;
}
int main()
{
    vector<vector <int>> arr  = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    int target = 99;
    if(findTarget(arr, target) == false)
    {
        cout<<"Not found";
    }

}