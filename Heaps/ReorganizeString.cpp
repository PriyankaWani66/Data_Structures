//Leetcode 767. Reorganize String

#include <string>
#include<iostream>
#include <queue>
#include<vector>
using namespace std;

class node{
    public:
    char ch;
    int freq;

    node(char c, int f){
        ch = c;
        freq = f;
    }
};

class compare{
    public:
    bool operator()(node a, node b){
        return a.freq < b.freq; // max heap based on frequency
    }
};

string reorganizeString(string s)
{
    priority_queue<node,vector<node>,compare> maxHeap;
    
    //frequency array
    int arr[26] = {0};

    for(int i=0;i<s.length();i++){
        char ch = s[i];
        arr[ch-'a']++;
    }

    //insert all characters with their frequencies into the max heap
    for(int i=0;i<26;i++){
        if(arr[i]!=0){
            node temp(i+'a',arr[i]);
            maxHeap.push(temp);
        }
    }

    string ans = "";

    while(maxHeap.size()>1){
        node first = maxHeap.top();
        maxHeap.pop();
        node second = maxHeap.top();
        maxHeap.pop();

        ans += first.ch;
        ans += second.ch;

        first.freq--;
        second.freq--;

        if(first.freq>0){
            maxHeap.push(first);
        }
        if(second.freq>0){
            maxHeap.push(second);
        }
    }

    if(maxHeap.size()==1){
        node last = maxHeap.top();
        if(last.freq>1){
            ans = "";
        }
        else{
            ans += last.ch;
        }
    }
    return ans;
}
int main(){
    string s = "aaab";
    string result = reorganizeString(s);
    if(result==""){
        cout << "Not possible to reorganize the string" << endl;
    }   
    else{
        cout << result << endl;
    }
    return 0;
}