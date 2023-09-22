
// Approach 1 (better tho)

class Solution
{
public:
    string longestCommonPrefix(vector<string> &v)
    {
        if (v.empty())
        {
            return "";
        }

        string answer = "";
        int len = v[0].length();

        for (int i = 0; i < len; ++i)
        {
            char current = v[0][i];

            for (const string &s : v)
            {
                if (i >= s.length() || s[i] != current)
                {
                    return answer;
                }
            }

            answer += current;
        }

        return answer;
    }
};

//  Approach 2 - by using trie

class TrieNode
{
public:
    TrieNode *children[26];
    int childCount;
    bool isEndOfWord;

    TrieNode()
    {
        for (int i = 0; i < 26; ++i)
        {
            children[i] = nullptr;
        }
        childCount = 0;
        isEndOfWord = false;
    }
};

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        TrieNode *root = new TrieNode();

        // Build the trie
        for (const string &s : strs)
        {
            TrieNode *current = root;
            for (char c : s)
            {
                int index = c - 'a';
                if (!current->children[index])
                {
                    current->children[index] = new TrieNode();
                    current->childCount++;
                }
                current = current->children[index];
            }
            current->isEndOfWord = true;
        }

        string answer = "";
        TrieNode *current = root;

        // Traverse the trie
        while (current->childCount == 1 && !current->isEndOfWord)
        {
            for (int i = 0; i < 26; ++i)
            {
                if (current->children[i])
                {
                    answer += ('a' + i);
                    current = current->children[i];
                    break;
                }
            }
        }

        return answer;
    }
};