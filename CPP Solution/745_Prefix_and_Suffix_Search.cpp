// Link: https://leetcode.com/problems/prefix-and-suffix-search/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class WordFilter {
public:
    map<string,int>mp;
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            for(int j=0;j<=words[i].size();j++){
                for(int k=words[i].size();k>=0;k--){
                    mp[words[i].substr(0,j)+"#"+words[i].substr(k)] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return mp.count(prefix+"#"+suffix)?mp[prefix+"#"+suffix]:-1;
    }
};

int main()
{
    vector<string> words = {"apple"};
    WordFilter obj(words);
    cout << obj.f("a", "e") << endl;
    return 0;
}
