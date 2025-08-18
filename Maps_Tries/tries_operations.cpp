#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode* children[26]; //26 because each node can have letters from a-a i.e, 25

    TrieNode(char ch)
    {
        this->data = ch;
        this->isTerminal = false;
        for(int i=0;i<26;i++){
            children[i]= NULL;
        }
    }
};

void insertNode(TrieNode* root, string word)
{
    cout << "Inserting " << word << endl;
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
        root->children[index]=child;
    }

    //recursion
    insertNode(child,word.substr(1));
}

bool searchWord(TrieNode* root, string word){
    //B.C
    if(word.length()==0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch-'a';
    TrieNode* child;

    //present
    if(root->children[index]!=NULL){
        child = root->children[index];
    }
    else{
        return false;
    }
    return searchWord(child, word.substr(1));
}

void deleteWord(TrieNode* root, string word) {
    //B.C
    if(word.length() == 0) {
        if(root->isTerminal) {
            root->isTerminal = false; // Mark the node as non-terminal
        }
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    // Check if the child exists
    if(root->children[index] != NULL) {
        deleteWord(root->children[index], word.substr(1));
    }
    else{
        // If the child does not exist, the word is not in the trie
        return;
    }
}

int main(){
    TrieNode* root = new TrieNode('\0'); //dummy root node
    insertNode(root,"hello");
    insertNode(root,"help");
    insertNode(root,"priyanka");
    insertNode(root,"priya");

    cout << "Searching for 'hello': " << (searchWord(root, "hello") ? "Found" : "Not Found") << endl;
    deleteWord(root, "hello");
    cout<<"After deleting"<<endl;    
    cout << "Searching for 'hello': " << (searchWord(root, "hello") ? "Found" : "Not Found") << endl;
    return 0;
}

/* 
For a single operation (insert/search/delete):
Time Complexity: O(L)
Space Complexity: O(L) [recursion stack only]
*/

/*
For the entire trie:
Space Complexity: O(N * L * 26) in worst case
N = number of words, L = average word length
*/

//you can use unordered_map instead of array to reduce space complexity