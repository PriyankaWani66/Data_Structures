//Leetcode question: 14

#include<iostream>
#include<vector>
using namespace std;


//T.C = O(N*M) => N = number of strings, M = length of first string
//S.C = O(1) => no extra space used
string LCP_brutforce(vector<string> &strs){
    string prefix = "";
    for(int i=0;i<strs[0].length();i++){
        char ch = strs[0][i];
        bool match = true;

        for(int j=1;j<strs.size();j++){
            if(strs[j].length()<i||ch!=strs[j][i])
            {
                match = false;
                break;
            }
        }
        if(match==false){
            break;
        }
        else{
            prefix+=ch;
        }
    }
    return prefix;
}

//method 2: using trie
//T.C = O(N*M) => N = number of strings, M = length of first string
//S.C = O(N*M) => in worst case all strings are different
class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode* children[26]; //26 because each node can have letters from a-a i.e, 25
    int childCount; //we need this to count number of children of a node

    TrieNode(char ch)
    {
        this->data = ch;
        this->isTerminal = false;
        for(int i=0;i<26;i++){
            children[i]= NULL;
        }
        this->childCount = 0;
    }
};

void insertWord(TrieNode* root, string word)
{
    //cout << "Inserting " << word << endl;
    //B.C
    if(word.length()==0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    //present
    if(root->children[index]!=NULL)
    {
        child = root->children[index];
    }
    else{
        child = new TrieNode(ch);
        root->childCount++;
        root->children[index]=child;
    }

    //recursion
    insertWord(child,word.substr(1));
}

void findLCPUsingTrie(TrieNode* root, string first, string &prefix){
    if(root->isTerminal == true){
        return;
    }

    for(int i=0;i<first.length();i++){
        char ch =  first[i];
        if(root->childCount==1){
            prefix+=ch;
            int index = ch-'a';
            root = root->children[index];
        }
        else{
            break;
        }
        if(root->isTerminal==true){
            break;
        }
    }

}
int main(){
    vector<string> strs = {"code","coder","codehelper"};
    string ans = LCP_brutforce(strs);
    cout << "Longest Common Prefix using Brute Force approach: " << ans << endl;

    //using trie
    string first = strs[0];
    TrieNode* root = new TrieNode('\0');

    //insert all words in trie
    for(int i=0;i<strs.size();i++){
        insertWord(root,strs[i]);
    }
    string prefix="";
    findLCPUsingTrie(root,first,prefix);
    cout << "Longest Common Prefix using Trie: " << prefix << endl;
    return 0;
}

