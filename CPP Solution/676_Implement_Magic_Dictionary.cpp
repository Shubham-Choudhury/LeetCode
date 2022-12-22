// Link: https://leetcode.com/problems/implement-magic-dictionary/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {}
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto x: dict) m[x.size()].push_back(x);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(auto x: m[word.size()])
            if(oneEditDistance(x, word)) return true;
        return false;
    }
    
private:
    unordered_map<int, vector<string>>m;
    bool oneEditDistance(string& a, string& b){
        int diff = 0;
        for(int i = 0; i < a.size() && diff <= 1; i++)
            if(a[i] != b[i]) diff++;
        return diff == 1;
    }
};

int main()
{
    MagicDictionary obj;
    vector<string> dict = {"hello", "leetcode"};
    obj.buildDict(dict);
    cout << obj.search("hello") << endl;
    cout << obj.search("hhllo") << endl;
    cout << obj.search("hell") << endl;
    cout << obj.search("leetcoded") << endl;
    return 0;
}
