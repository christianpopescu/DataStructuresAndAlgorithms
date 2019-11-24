#include <bits/stdc++.h>
#include <iostream>

#define INDEX(chr) chr - 'a'

class TrieIterator;

class CompressedTrieNode {
public:
    CompressedTrieNode* child[26];
    bool isTerminal;
    std::string theLabel;
  TrieNode()
    : theLabel("") {
        isTerminal = false;
        for (int i=0; i<26; ++i) child[i] = nullptr;
    }
    friend TrieIterator;
};

class TrieAsWordList {
    CompressedTrieNode root;
public:
  TrieAsWordList() {
  }

  void AddWordToNode(CompressedTrieNode* node, const std::string wordToAdd)
  {
    int nw = wordToAdd.size();
    int index = wordToAdd[0] - 'a';
    if (current->child[index] = nullptr) {
      current->child[index] = new CompresseTrieNode;
      current->child[index]->theLabel = wordToAdd;
      current->child[index]->isTerminal = true;
    } else if (wordToAdd == current->theLabel) {
      current->isTerminal = true;
    } else {
      int i=0;
      int nc =  current->theLabel.size();
      while (  i < nc && i <nw && current->theLabel[i] == wordToAdd[i])
	++i;
      // theLabel prefixes wordToAdd
      if ( i == nc) {
	// match till now and word to add is longer than the current node label
	char ch wordToAdd[i];
	int loop_index = ch -'a'
	if (current->child[loop_index ] == nullptr) {   
	  // there is no child -> create one
	  current->child[loop_index] = new CompressedTrieNode;
	  current->child[loop_index]->theLabel = wordToAdd.substr(i);
	  current->child[loop_index]->isTerminal = true;
	} else {
	  // ther is one child -> recursively call function with this child and the rest of the word
		AddWordToNode(current->child[loop_index ], wordToAdd.substr(i));
	}
	  
      } if (i == nw) {
	// match till now and the current label is longer than the word to add
	// ->split the node in two nodes
	CompressedTrieNode* bkp = node; // save current node
	node = new CompressedTrieNode;
	node->theLabel = wordToAdd.substr(0,i);
	node->isTerminal = true;
	node->child[bkp->theLabel[i] - 'a'] = bkp;
	bkp->theLabel = bkp->theLabel.substr(i); 
      } else { 
	// match till now but rest some characters on both side
	// -> split the current node in two nodes that have two child nodes
	//      -> the rest of the current node
	//      -> a new node that contains the rest of word to add
        // split
	CompressedTrieNode* bkp = node; // save current node
	node = new CompressedTrieNode;
	node->theLabel = wordToAdd.substr(0,i);
	node->child[bkp->theLabel[i] - 'a'] = bkp;
	bkp->theLabel = bkp->theLabel.substr(i); 
	// add new node
	int loop_index = wordToAdd[i] - 'a' 
	node->child[loop_index] = new CompressedTrieNode;
	node->child[loop_index]->theLabel = wordToAdd.substr(i);
	node->child[loop_index}->isTerminal = true;
      }
	       
    }
    
    
  }
  
     void AddWordToList(const std::string& wordToAdd) {
        unsigned long n = wordToAdd.size() ;
        TrieNode* current = &root;
        int index = 0;
        for (int i=0; i<n; ++i) {
	  index = wordToAdd[i] - 'a';
	  if (current->child[index] == nullptr) 
	  
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
