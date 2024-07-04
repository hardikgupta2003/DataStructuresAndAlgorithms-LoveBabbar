#include <iostream>
using namespace std;

class TrieNode
{
public:
    char value;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode() : value('-'), isTerminal(false)
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }

    TrieNode(char val) : value(val), isTerminal(false)
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

// insertion
void insertWord(TrieNode *root, string word)
{
    // cout << "recieved word: " << word << " for insertion " << endl;
    // base case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
        // present
        child = root->children[index];
    }
    else
    {
        // absent
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recursion
    insertWord(child, word.substr(1));
}
bool searchWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    if (root->children[index] != NULL)
    {
        // present or found
        child = root->children[index];
    }
    else
    {
        // not found
        return false;
    }

    /// baaaki recursion
    bool recursionKaAns = searchWord(child, word.substr(1));
    return recursionKaAns;
}
bool searchWord(TrieNode* root, string word) {
  //base case
  if(word.length() == 0) {
    return root->isTerminal;
  }

  char ch = word[0];
  int index = ch - 'a';
  TrieNode* child;

  if(root->children[index] != NULL) {
    //present or found
    child = root->children[index];
  }
  else {
    //not found
    return false;
  }

  ///baaaki recursion
  bool recursionKaAns = searchWord(child, word.substr(1));
  return recursionKaAns;

}

int main()
{
    TrieNode *root = new TrieNode();

    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "com");
    insertWord(root, "lover");
    insertWord(root, "loved");
    insertWord(root, "load");
    insertWord(root, "lov");
    insertWord(root, "bat");
    insertWord(root, "cat");
    insertWord(root, "car");

    cout << "Insertion Done" << endl;
    if (searchWord(root, "loved"))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
}
