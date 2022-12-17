// Link: https://leetcode.com/problems/stream-of-characters/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isWord;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isWord = false;
    }
};

class StreamChecker
{
public:
    TrieNode *root;
    string s;
    StreamChecker(vector<string> &words)
    {
        root = new TrieNode();
        for (string word : words)
        {
            TrieNode *node = root;
            for (int i = word.size() - 1; i >= 0; i--)
            {
                int c = word[i] - 'a';
                if (node->children[c] == nullptr)
                {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->isWord = true;
        }
    }

    bool query(char letter)
    {
        s += letter;
        TrieNode *node = root;
        for (int i = s.size() - 1; i >= 0 && node != nullptr; i--)
        {
            int c = s[i] - 'a';
            node = node->children[c];
            if (node != nullptr && node->isWord)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<string> words = {"cd", "f", "kl"};
    StreamChecker *obj = new StreamChecker(words);
    cout << obj->query('a') << endl;
    cout << obj->query('b') << endl;
    cout << obj->query('c') << endl;
    cout << obj->query('d') << endl;
    cout << obj->query('e') << endl;
    cout << obj->query('f') << endl;
    cout << obj->query('g') << endl;
    cout << obj->query('h') << endl;
    cout << obj->query('i') << endl;
    cout << obj->query('j') << endl;
    cout << obj->query('k') << endl;
    cout << obj->query('l') << endl;
    return 0;
}
