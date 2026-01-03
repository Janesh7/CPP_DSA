# Introduction to trie

**Trie Data Structure:**

**Introduction to Trie:**
- A trie (pronounced as "try") is a tree-like data structure used for efficient storage and retrieval of a dynamic set of strings or keys.
- Each node in a trie represents a single character, and paths from the root node to leaf nodes form words or strings.
- Tries are commonly used for dictionary-like operations, autocomplete, and searching for words with common prefixes.

**Trie Implementation:**
- Tries can be implemented in various ways, but one common approach is using an array of Trie nodes, each of size 26 (assuming lowercase English letters). This array allows us to efficiently map characters to child nodes.

**Insertion in a Trie:**

**Algorithm for Insertion:**
1. Start at the root node.
2. For each character in the string to insert:
   - Calculate the index of the character in the array (e.g., 'a' -> 0, 'b' -> 1, ..., 'z' -> 25).
   - If the corresponding child node exists, move to that node.
   - If the child node does not exist, create a new node and attach it as the child of the current node.
3. Once all characters are processed, mark the last node as the end of a word (usually by setting a flag).

**Pseudocode for Insertion:**
```cpp
class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (!current->children[index]) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }
};
```

**Time Complexity for Insertion:**
- The time complexity for insertion in a trie is O(L), where L is the length of the string being inserted.
- This is because we need to traverse through each character in the string.

**Space Complexity for Insertion:**
- The space complexity for insertion depends on the number of nodes created during the insertion process. In the worst case, if there are no common prefixes, it could be O(26*L), where L is the average length of the words.

## Search in a Trie:

**Algorithm for Search:**
1. Start at the root node.
2. For each character in the target string:
   - Calculate the index of the character in the array.
   - If the corresponding child node exists, move to that node.
   - If the child node does not exist, the target string is not in the trie, and you can return false.
3. After processing all characters, check if the current node is marked as the end of a word. If yes, the target string is found; otherwise, it is not present.

**Pseudocode for Search:**
```cpp
class Trie {
public:
    bool search(string word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (!current->children[index]) {
                return false;
            }
            current = current->children[index];
        }
        return current->isEndOfWord;
    }
};
```

**Time Complexity for Search:**
- The time complexity for search in a trie is O(L), where L is the length of the target string.
- Similar to insertion, we need to traverse through each character in the target string.

**Space Complexity for Search:**
- The space complexity for search is O(1) because it does not require additional memory beyond the traversal.

## Deletion in a Trie:

**Algorithm for Deletion:**
1. Start at the root node.
2. Traverse through the characters in the target string.
3. When reaching the end of the string, mark the corresponding node as not the end of a word (i.e., `isEndOfWord` = false).
4. If the node has no other children, remove it (i.e., set the corresponding entry in the array to null).
5. Continue this process for each character until you reach the end of the string or find that the string is not present.

**Pseudocode for Deletion:**
```cpp
class Trie {
public:
    bool delete(string word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (!current->children[index]) {
                return false; // Word not found, cannot delete.
            }
            current = current->children[index];
        }
        
        if (!current->isEndOfWord) {
            return false; // Word not found, cannot delete.
        }
        
        current->isEndOfWord = false; // Mark as not the end of a word.
        return true; // Word found and deleted successfully.
    }
};
```

**Time Complexity for Deletion:**
- The time complexity for deletion is O(L), where L is the length of the target string.

**Space Complexity for Deletion:**
- The space complexity for deletion is O(1) because it does not require additional memory beyond the traversal.

## Different Ways to Implement Trie:

1. Using an array of size 26 (for lowercase English letters) to represent child nodes, as demonstrated in the pseudocode above.
2. Using a hash map or a dictionary where keys are characters, and values are corresponding child nodes.
3. Using a combination of arrays and flags for each character's existence.

Each implementation has its trade-offs in terms of space and time complexity, and the choice depends on the specific use case and requirements.


**1. Using an Array of Size 26:**
   - In this implementation, we use a fixed-size array of 26 elements to represent the child nodes for each character (assuming lowercase English letters).
   - This approach is memory-efficient but not very flexible if the character set is not known in advance.
  

**2. Using a Hash Map or Dictionary:**
   - In this implementation, each node has a dynamic map (or dictionary) where keys are characters, and values are corresponding child nodes.
   - This approach is more flexible and suitable for handling any character set, but it can be memory-intensive.

**Pseudocode for Trie with Hash Map:**
```cpp
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }
    // Search and delete methods are similar to the previous explanation.
};
```


# Questions

## Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

**Approach 1: Normal Iteration**

**Algorithm:**
1. Start with the first character of the first string.
2. For each character position from left to right:
   - Check if all the strings have the same character at that position.
   - If they do, append that character to the answer.
   - If any of the strings don't have the same character or if the string is finished, break and return the answer.

**Pseudocode for Approach 1:**
```cpp
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }
    
    string answer = "";
    int len = strs[0].length();
    
    for (int i = 0; i < len; ++i) {
        char current = strs[0][i];
        
        for (const string& s : strs) {
            if (i >= s.length() || s[i] != current) {
                return answer;
            }
        }
        
        answer += current;
    }
    
    return answer;
}
```

**Time Complexity for Approach 1:**
- Let n be the number of strings in the input, and m be the average length of the strings.
- In the worst case, we iterate through all characters in all strings, so the time complexity is O(n * m).

**Space Complexity for Approach 1:**
- The space complexity is O(1) because we use a constant amount of extra space for the answer and other variables.

**Approach 2: Using Trie**

**Algorithm:**
1. Build a trie using the characters of the strings.
2. While traversing the trie, keep track of the number of children each node has.
3. If a node has more than one child or if it's marked as the end of a string, stop and return the answer.
4. Otherwise, keep traversing the trie and adding characters to the answer.

**Pseudocode for Approach 2:**
```cpp
class TrieNode {
public:
    TrieNode* children[26];
    int childCount;
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        childCount = 0;
        isEndOfWord = false;
    }
};

string longestCommonPrefix(vector<string>& strs) {
    TrieNode* root = new TrieNode();
    
    // Build the trie
    for (const string& s : strs) {
        TrieNode* current = root;
        for (char c : s) {
            int index = c - 'a';
            if (!current->children[index]) {
                current->children[index] = new TrieNode();
                current->childCount++;
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }
    
    string answer = "";
    TrieNode* current = root;
    
    // Traverse the trie
    while (current->childCount == 1 && !current->isEndOfWord) {
        for (int i = 0; i < 26; ++i) {
            if (current->children[i]) {
                answer += ('a' + i);
                current = current->children[i];
                break;
            }
        }
    }
    
    return answer;
}
```

**Time Complexity for Approach 2:**
- Let n be the number of strings in the input, and m be the average length of the strings.
- Building the trie takes O(n * m) time.
- Traversing the trie takes O(m) time in the worst case (if there are no branches in the trie).
- So, the overall time complexity is O(n * m).

**Space Complexity for Approach 2:**
- The space complexity is O(n * m) because we need to store the characters of all strings in the trie.
- In the worst case, when there are no common prefixes, the space complexity is O(n * m).



## Implementing a Phone Directory using Trie

### Approach
We can implement a phone directory using a Trie data structure. The Trie will store the contact names, and for each contact, we'll insert its characters into the Trie. To retrieve suggestions for a query string, we'll traverse the Trie based on the query and print all the end words from there. We'll maintain a pointer to the previous character to optimize the traversal.

### Trie Node Class
We'll define a TrieNode class with the following attributes:
- `char data`: Represents the character stored in the node.
- `TrieNode* children[26]`: An array of pointers to child nodes (one for each lowercase English letter).
- `bool isTerminal`: Indicates whether the node represents the end of a contact name.

### Trie Class
The Trie class will have the following methods:
- `insertUtil(TrieNode* root, string word)`: A recursive function to insert a word into the Trie.
- `insertWord(string word)`: Public method to insert a word into the Trie.
- `printSuggestions(TrieNode* curr, vector<string>& temp, string prefix)`: A recursive function to print all suggestions from a given node.
- `getSuggestions(string str)`: Returns a vector of vectors of strings representing suggestions for the query string.
- `phoneDirectory(vector<string>& contactList, string& queryStr)`: The main function to implement the phone directory.

### Pseudocode for Trie and Phone Directory Implementation

```cpp
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0'); // Initialize the root with a sentinel character.
    }

    void insertUtil(TrieNode* root, string word) {
        // Base case: If the word is empty, mark this node as the end of a word.
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        TrieNode* child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL) {
            // Child is present, traverse to the child.
            child = root->children[index];
        } else {
            // Child is absent, create a new node for the character.
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // Recursive function to insert the rest of the word.
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word); // Start inserting from the root.
    }

    void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix); // If it's the end of a word, add it to the suggestions.
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr->children[ch - 'a'];
            if (next != NULL) {
                // Character matched, traverse to the child.
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str) {
        TrieNode* prev = root; // Start traversal from the root.
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.size(); i++) {
            char lastChar = str[i];
            prefix.push_back(lastChar);

            // Check for the last character in the Trie.
            TrieNode* curr = prev->children[lastChar - 'a'];
            if (curr == NULL) {
                // Not present, break and return current suggestions.
                break;
            }

            vector<string> temp; // For storing all suggestions.
            printSuggestions(curr, temp, prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr; // Move to the next node.
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>& contactList, string& queryStr) {
    Trie* t = new Trie();

    // Insert all contacts into the Trie.
    for (int i = 0; i < contactList.size(); i++) {
        string str = contactList[i];
        t->insertWord(str);
    }

    // Return suggestions for the query string.
    return t->getSuggestions(queryStr);
}
```

## Time Complexity
- Inserting a contact list into the Trie takes O(N * M) time, where N is the number of contacts and M is the average length of a contact name.
- Retrieving suggestions for a query string takes O(K * L) time, where K is the length of the query string, and L is the length of the longest suggestion found in the Trie.

## Space Complexity
- The space complexity is O(N * M) for storing the Trie structure, where N is the number of contacts, and M is the average length of a contact name.