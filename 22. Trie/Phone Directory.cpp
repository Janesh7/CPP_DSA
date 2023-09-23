class TrieNode {

public:
  char data;

  TrieNode *children[26];

  bool isTerminal;

  TrieNode(char ch)

  {

    data = ch;

    for (int i = 0; i < 26; i++)

    {

      children[i] = NULL;
    }

    isTerminal = false;
  }
};

class Trie {

public:
  TrieNode *root;

  Trie() { root = new TrieNode('\0'); }

  void insertUtil(TrieNode *root, string word)

  {

    // base case

    if (word.size() == 0)

    {

      root->isTerminal = true;

      return;
    }

    TrieNode *child;

    int index = word[0] - 'a';

    if (root->children[index] != NULL)

    {

      // child is present

      child = root->children[index];

    }

    else

    {

      // child is absent

      child = new TrieNode(word[0]);

      root->children[index] = child;
    }

    // recursive function

    insertUtil(child, word.substr(1));
  }

  void insertWord(string word)

  {

    insertUtil(root, word);
  }

  void printSugesstions(TrieNode *curr, vector<string> &temp, string prefix)

  {

    if (curr->isTerminal)

    {

      temp.push_back(prefix);
    }

    for (char ch = 'a'; ch <= 'z'; ch++)

    {

      TrieNode *next = curr->children[ch - 'a'];

      if (next != NULL)

      {

        // character matched

        prefix.push_back(ch);

        printSugesstions(next, temp, prefix);

        prefix.pop_back();
      }
    }
  }

  vector<vector<string>> getSugesstions(string str)

  {

    TrieNode *prev = root;

    vector<vector<string>> output;

    string prefix = "";

    for (int i = 0; i < str.size(); i++)

    {

      char lastChar = str[i];

      prefix.push_back(lastChar);

      // check for lst character

      TrieNode *curr = prev->children[lastChar - 'a'];

      if (curr == NULL)

      {

        // not present

        break;
      }

      // if found

      vector<string> temp; // for storing all sugesstions

      printSugesstions(curr, temp, prefix);

      output.push_back(temp);

      temp.clear();

      prev = curr;
    }

    return output;
  }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList,
                                      string &queryStr)

{

  Trie *t = new Trie();

  // insert all contact in trie

  for (int i = 0; i < contactList.size(); i++)

  {

    string str = contactList[i];

    t->insertWord(str);
  }

  // return ans

  return t->getSugesstions(queryStr);
}
