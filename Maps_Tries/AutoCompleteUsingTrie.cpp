#include<vector>
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

void insertWord(TrieNode* root, string word) {
        //cout << "Inserting " << word << endl;
   //base case
        if(word.length() == 0) {
                root->isTerminal = true;
                return;
        }
        
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;
        //present
        if(root->children[index] != NULL) {
                child = root->children[index];
        }
        else {
                //not present
                child = new TrieNode(ch);
                root->children[index] = child;
        }

        //recursion sambhal lega
        insertWord(child, word.substr(1));
}

void storeSuggestions(TrieNode* curr, vector<string>& temp, string &prefix){
    if(curr->isTerminal)
    {
        temp.push_back(prefix);
    }

    for(char ch = 'a'; ch<='z';ch++)
    {
        int index = ch-'a';
        TrieNode* next = curr->children[index];

        if(next!=NULL)
        {
            prefix.push_back(ch);
            storeSuggestions(next,temp,prefix);
            prefix.pop_back();
        }
    }
}

vector<vector<string>> getSuggestions(TrieNode* root, string str){
    vector<vector<string>> output;
    TrieNode* prev = root;
    string prefix = "";

    for(int i=0;i<str.size();i++)
    {
        char lastch = str[i];

        int index = lastch-'a';
        TrieNode* curr = prev->children[index];

        if(curr==NULL){
            break;
        }
        else{
            vector<string> temp;
            prefix.push_back(lastch);
            storeSuggestions(curr,temp,prefix);
            output.push_back(temp);
            prev = curr;
        }
    }
    return output;
}
int main(){
    vector<string> v;
	v.push_back("love");
	v.push_back("lover");
	v.push_back("loving");
	v.push_back("last");
	v.push_back("lost");
	v.push_back("lane");
	v.push_back("lord");

    //auto suggestion string
    string str = "lovi";

    //TrieNode object
    TrieNode* root = new TrieNode('\0');
    
    //insert words in trie
    for(int i=0;i<v.size();i++)
    {
        insertWord(root,v[i]);
    }

    vector<vector<string>> output = getSuggestions(root, str);
    
	cout << "Printing the answer: " << endl;

	for(int i=0; i<output.size(); i++) {
		for(int j=0; j<output[i].size(); j++) {
			cout << output[i][j]<<", ";
		}
		cout << endl;
	}

    return 0;
}

/*
Time Complexity:
1) Insertion: O(N*M)   // N = number of words, M = length of each word
2) Suggestions: O(L + K*M) 
   // L = length of prefix, K = number of matching words
   // Worst case: O(N*M + L)

Space Complexity:
O(N*M)   // total characters stored in the Trie
*/
