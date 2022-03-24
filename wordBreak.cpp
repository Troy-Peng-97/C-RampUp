#include <iostream>
#include <vector>
using namespace std;
struct TrieNode {
    TrieNode* children[26] = {NULL};
    bool isWord = false;
};

void insertWord(TrieNode* root, string word){
    for (char& c : word){
        if (!root->children[c - 'a']){
            root->children[c - 'a'] = new TrieNode();
        }
        root = root->children[c - 'a'];
    }
    root->isWord = true;
}
bool wordBreak(string s, vector<string>& wordDict) {
    TrieNode* root = new TrieNode();
    for (string& word : wordDict){
        insertWord(root, word);
    }
    int n = s.size();
    // record whether the subarray start at index i could break;
    vector<int> record(n + 1);
    record[n] = 1; // base case for the right end

    for (int i = n - 1; i >= 0; i--){
        TrieNode* cur = root;
        for (int j = i; j < n; j++){
            char c = s[j];
            if (cur->children[c - 'a']){
                cur = cur->children[c - 'a'];
                // if substring(i, j) is a word && substring(j + 1, end) is also a valid word break;
                if (cur->isWord && record[j + 1]){
                    record[i] = 1;
                }
            }
            else {
                break;
            }
        }
    }
    return record[0] == 1;
}
// To execute C++, please define "int main()"
int main() {
    vector<string> words = {"leet", "code"};
    cout << wordBreak("leetcode", words);
    return 0;
}
