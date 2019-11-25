#include <bits/stdc++.h>
#include <iostream>

using namespace std;
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
    cout << label << "    " << terminal << endl;
    for (int i=0; i<26; ++i) child[i] = nullptr;
  }
};

class TrieAsWordList {
public:
  CompressedTrieNode* root;
public:
  TrieAsWordList() {
    root = new CompressedTrieNode("",false);
  }
  void AddWordToRoot(CompressedTrieNode*& node, const std::string wordToAdd)
  {
    int index = wordToAdd[0] - 'a';
    
        if (node->child[index] == nullptr) {
          node->child[index] = new CompressedTrieNode (wordToAdd, true);
	} else {
	  AddWordToNode(node->child[index], wordToAdd);
	}
  }
  
  void AddWordToNode(CompressedTrieNode*& node, const std::string wordToAdd)
  {
    cout << "Word to add " << wordToAdd << endl;
    CompressedTrieNode* current = node;
    //int index = wordToAdd[0] - 'a';
    //    if (current->child[index] = nullptr) {
    //      current->child[index] = new CompressedTrieNode (wordToAdd, true);
    // } else
    if (wordToAdd == current->theLabel) {
      current->isTerminal = true;
    } else {
      int i=0;
      int nw = wordToAdd.size();
      int nc =  current->theLabel.size();
      while (  i < nc && i <nw && current->theLabel[i] == wordToAdd[i]) ++i;
      if ( i == nc) {
        // theLabel prefixes wordToAdd
	// match till now and word to add is longer than the current node label
	int index = wordToAdd[i] -'a';
	if (current->child[index ] == nullptr) {   
	  // there is no child -> create one
	  current->child[index] = new CompressedTrieNode ( wordToAdd.substr(i), true);
	} else {
	  // ther is one child -> recursively call function with this child and the rest of the word
	  AddWordToNode(current->child[index ], wordToAdd.substr(i));
	}
      } else if (i == nw) {
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
	node->child[ wordToAdd[i] - 'a'] = new CompressedTrieNode(wordToAdd.substr(i), true);
      }
	       
     }
  }
  void printRoot() {
    for (int i=0; i<26; ++i)
      {
	if (root->child[i] != nullptr) {
	  cout << "from root " << (char)(i+'a') << endl;
	  printNode(root->child[i]);
	}
      }
  }
  void printNode(CompressedTrieNode* node) {
    cout << node->theLabel << endl; 
    for (int i=0; i<26; ++i)
      {
	if (node->child[i] != nullptr) printNode(node->child[i]);
      }
  }
};

int main() {
    TrieAsWordList trieAsWordList;
    trieAsWordList.AddWordToRoot(trieAsWordList.root, "toto");
    trieAsWordList.AddWordToRoot (trieAsWordList.root, "titi");
    trieAsWordList.AddWordToRoot (trieAsWordList.root, "tital");
    cout << " I am here" << endl;

    trieAsWordList.printRoot();
    
    std::cout << "--- End of Program ---" << std::endl;
    return 0;
}
