#include <bits/stdc++.h>
#include <iostream>

#define INDEX(chr) chr - 'a'

class TrieIterator;

class CompressedTrieNode {
public:
    CompressedTrieNode* child[26];
    bool isTerminal;
    std::string theLabel;
  CompressedTrieNode()
    : theLabel("") {
        isTerminal = false;
        for (int i=0; i<26; ++i) child[i] = nullptr;
    }
  CompressedTrieNode(std::string label, bool terminal) :
    theLabel(label),
    isTerminal(terminal) {
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
      current->child[index] = new CompressedTrieNode (wordToAdd, true);
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
	  current->child[loop_index] = new CompressedTrieNode ( wordToAdd.substr(i), true);
	} else {
	  // ther is one child -> recursively call function with this child and the rest of the word
	  AddWordToNode(current->child[loop_index ], wordToAdd.substr(i));
	}
	  
      } if (i == nw) {
	// match till now and the current label is longer than the word to add
	// ->split the node in two nodes
	CompressedTrieNode* bkp = node; // save current node
	node = new CompressedTrieNode (wordToAdd.substr(0,i), true);
	node->child[bkp->theLabel[i] - 'a'] = bkp;
	bkp->theLabel = bkp->theLabel.substr(i); 
      } else { 
	// match till now but rest some characters on both side
	// -> split the current node in two nodes that have two child nodes
	//      -> the rest of the current node
	//      -> a new node that contains the rest of word to add
        // split
	CompressedTrieNode* bkp = node; // save current node
	node = new CompressedTrieNode (wordToAdd.substr(0,i), false);
	node->child[bkp->theLabel[i] - 'a'] = bkp;
	bkp->theLabel = bkp->theLabel.substr(i); 
	// add new node
	node->child[ wordToAdd[i] - 'a'] = new CompressedTrieNode(wordToAdd.substr(0,i), true);
      }
	       
    }
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
