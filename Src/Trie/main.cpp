#include <bits/stdc++.h>
#include <iostream>

class TrieNode {
public:
    char value;
    TrieNode* children[26];
    bool isTerminal;
    std::string theWord;
    TrieNode() {
        isTerminal = false;
        for (int i=0; i<26; ++i) children[i] = nullptr;
    }
};

class TrieAsWordList {
    TrieNode root;
public:
    TrieAsWordList() {
        root.value = '$';    // special value for root

    }

     void AddWordToList(const std::string& wordToAdd) {
         unsigned long n = wordToAdd.size() + 1;
         char wrd [n];
        std::strcpy(wrd,wordToAdd.c_str());
        TrieNode* current = &root;
/*        for (int i=0; i<n; ++i) {
            if (current->children[wrd[i]-'a'] == nullptr) {
                current->children[wrd[i]-'a'] = new TrieNode();
                current->children[wrd[i]-'a']->value = wrd[i];
                current = current->children[wrd[i]-'a'];
            }
            current  = current->children[wrd[i]-'a'];
        }c
        current->isTerminal = true;
        current->theWord = wordToAdd;*/
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    TrieAsWordList trieAsWordList;
    trieAsWordList.AddWordToList("toto");
    return 0;
}