//Find the first occurrence of a repeating element using Unordered hashing - GeeksforGeeks Question.

#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    int a[] = {1,2,2,3};
    int size = 4;

    unordered_map<int, int>hash;

    for(int i=0;i<size;i++)
    {
        hash[a[i]]++;
    }

    for(int i=0;i<size;i++)
    {
        if(hash[a[i]] > 1)
        {
            cout<<i;
            return 0;
        }
    }
    


    return 0;
}