// Link: https://leetcode.com/problems/implement-trie-prefix-tree/

#include <iostream>
#include <string>
using namespace std;

class Trie {
public:
    
    Trie* children[26];
    bool isEnd;
    Trie() {
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* curr = this;
        for(char c: word){
            if(curr->children[c - 'a'] == NULL)
                curr->children[c - 'a'] = new Trie();
            curr = curr->children[c - 'a'];
        }
        curr->isEnd = true;
    }
    
    
    bool search(string word) {
        Trie* curr = this;
        for(char c: word){
            if(curr->children[c - 'a'] == NULL)
                return false;
            curr = curr->children[c - 'a'];
        }
        return curr->isEnd;
    }
    
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for(char c: prefix){
            if(curr->children[c - 'a'] == NULL)
                return false;
            curr = curr->children[c - 'a'];
        }
        return true;
    }
};

int main() {
    Trie* obj = new Trie();
    obj->insert("apple");
    cout << obj->search("apple") << endl;
    cout << obj->search("app") << endl;
    cout << obj->startsWith("app") << endl;
    obj->insert("app");
    cout << obj->search("app") << endl;
    return 0;
}
