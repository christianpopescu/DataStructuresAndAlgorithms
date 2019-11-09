#include <bits/stdc++.h>
#include <iostream>

#define INDEX(chr) chr - 'a'

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
         unsigned long n = wordToAdd.size() ;
         char wrd [n];
        std::strcpy(wrd,wordToAdd.c_str());
        TrieNode* current = &root;
        for (int i=0; i<n; ++i) {
            if (current->children[INDEX(wrd[i])] == nullptr) {
                current->children[INDEX(wrd[i])] = new TrieNode();
                current->children[INDEX(wrd[i])]->value = wrd[i];
                }
            current  = current->children[INDEX(wrd[i])];
        }
        current->isTerminal = true;
        current->theWord = wordToAdd;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    TrieAsWordList trieAsWordList;
    trieAsWordList.AddWordToList("toto");
    return 0;
}