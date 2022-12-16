// Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class WordDictionary
{
public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        TrieNode *p = root;
        for (auto &a : word)
        {
            if (p->children[a - 'a'] == nullptr)
                p->children[a - 'a'] = new TrieNode();
            p = p->children[a - 'a'];
        }
        p->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return search(word, root);
    }

private:
    struct TrieNode
    {
        TrieNode *children[26];
        bool isWord;
        TrieNode()
        {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
            isWord = false;
        }
    };
    TrieNode *root;

    bool search(string word, TrieNode *p)
    {
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == '.')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (p->children[j] != nullptr && search(word.substr(i + 1), p->children[j]))
                        return true;
                }
                return false;
            }
            else
            {
                if (p->children[word[i] - 'a'] == nullptr)
                    return false;
                p = p->children[word[i] - 'a'];
            }
        }
        return p->isWord;
    }
};

int main()
{
    WordDictionary a;
    a.addWord("bad");
    a.addWord("dad");
    a.addWord("mad");
    cout << a.search("pad") << endl;
    cout << a.search("bad") << endl;
    cout << a.search(".ad") << endl;
    cout << a.search("b..") << endl;
    return 0;
}
