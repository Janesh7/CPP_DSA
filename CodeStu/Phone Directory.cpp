// Implement a phone directory
// Hard


// You are given a list/array of strings which denotes the contacts that exist in your phone directory. The search query on a string ‘str’ which is a query string displays all the contacts which are present in the given directory with the prefix as ‘str’. One special property of the search function is that when a user searches for a contact from the contact list then suggestions (contacts with prefix as the string entered so for) are shown after the user enters each character.
// Note :
// If no suggestions are found, return an empty 2D array.
// For Example :
// alt text

// In the above example everytime we enter a character, a few suggestions display the strings which contain the entered string as prefixes.
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Constraints :
// 1 <= T <= 50
// 1 <= N <= 100
// 1 <= len <= 10
// ARR[i] contains lowercase English alphabets.

// All the given strings contain lowercase English alphabets.

// Time Limit: 1 sec.
// Sample Input 1 :
// 2
// 5
// cod coding codding code coly
// coding
// 2
// ninjas coding
// ninja
// Sample Output 1 :
// cod coding codding code coly
// cod coding codding code coly
// cod coding codding code coly
// coding
// coding
// coding
// ninjas
// ninjas
// ninjas
// ninjas
// ninjas
// Explanation To Sample Input 1 :
// In the first test case, 
// The suggestions for “c” is {“cod”, “coding”, “codding”, “code”, “coly”}.
// The suggestions for “co” is {“cod”, “coding”, “codding”, “code”, “coly”}.
// The suggestions for “cod” is {“cod”, “coding”, “codding”, “code”, “coly”}.
// The suggestion for “codi” is {“coding”}.
// The suggestion for “codin” is {“coding”}.
// The suggestion for “coding” is {“coding”}.

// In the second test case, 
// The suggestion for “n” is {“ninjas”}.
// The suggestion for “ni” is {“ninjas”}.
// The suggestion for “nin” is {“ninjas”}.
// The suggestion for “ninj” is {“ninjas”}.
// The suggestion for “ninja” is {“ninjas”}.
// Sample Input 2 :
// 3
// 2
// coding ninjas
// cell
// 2
// ab abc
// a
// 2
// ab abc
// b
// Sample Output 2 :
// coding
// ab abc
// No suggestions found
// Explanation To Sample Input 2 :
// In the first test case, 
// The suggestion for “c” is {“coding”}.
// For the rest of the letters, there are no suggestions.

// In the second test case,
// The suggestion for “a” is {“ab”, “abc”}.

In the third test case, no suggestions are found.


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
