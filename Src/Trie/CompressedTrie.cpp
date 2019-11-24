#include <bits/stdc++.h>
#include <iostream>

#define INDEX(chr) chr - 'a'

class TrieIterator;

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
    friend TrieIterator;
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

class TrieIterator {

public:
    TrieIterator (TrieNode* root) {
        first = root;
        current = 0;
        Visit(root);
        end = nullptr;
        listToIterate.push_back(end);

    }
    void First() {
        current = 0;
    }

    void Next() {
        current++;
    }

    TrieNode* Current() {
        return listToIterate[current];
    }

    TrieNode* End() {
        return listToIterate[listToIterate.size()-1];
    }

protected:
    TrieNode* first;
    TrieNode* end;
    int current;
    std::vector<TrieNode*> listToIterate;
    void Visit(TrieNode * node) {
        if (node == nullptr) return;
        listToIterate.push_back(node);
        for (int i = 0; i < 26; ++i) {
            if (node->children[i] != nullptr) Visit(node->children[i] );
        }
    }


};

int main() {
    std::cout << "Hello, World!" << std::endl;
    TrieAsWordList trieAsWordList;
    trieAsWordList.AddWordToList("toto");
    trieAsWordList.AddWordToList("titi");

    return 0;
}
