//To find maximum number of segments  ==> This problem is similar to the Minimum coins but we need max number of segments

#include<iostream>
#include<limits.h>
using namespace std;

int cutSegments(int n, int x, int y, int z)
{
    //B.C
    if(n==0)
    {
        return 0;
    }
    if(n<0)
    {
        return INT_MIN;
    }

    int ans1 = cutSegments(n-x,x,y,z) + 1;
    int ans2 = cutSegments(n-y,x,y,z) + 1;
    int ans3 = cutSegments(n-z,x,y,z) + 1;

    return max(ans1, max(ans2,ans3));

}
int main()
{
    int n = 8;
    int x = 3;
    int y = 2;
    int z = 2;

    int ans = cutSegments(n,x,y,z);

    //this is to get 0 for the paths that gives negative value (ignored paths)
    if(ans<0)
    {
        ans = 0;
    }
    cout<<ans;
}