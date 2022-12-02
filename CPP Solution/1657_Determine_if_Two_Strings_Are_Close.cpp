// Link: https://leetcode.com/problems/determine-if-two-strings-are-close/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool closeStrings(string w1, string w2) {
        int n1=w1.length();
        int n2=w2.length();
        if(n1!=n2)  return false;
        unordered_map<char,int>mp1;
        for(int i=0;i<n1;i++)
        {
            mp1[w1[i]]++;
        }
        unordered_map<char,int>mp2;
        for(auto it:w2)
        {
            mp2[it]++;
        }
        
        vector<int>v1;  vector<int>v2;
        vector<char>c1; vector<char>c2;
        for(auto it:mp1)
        {
            v1.push_back(it.second);
            c1.push_back(it.first);
        }
        for(auto ut:mp2)
        {
            v2.push_back(ut.second);
            c2.push_back(ut.first);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        sort(c1.begin(),c1.end());
        sort(c2.begin(),c2.end());
        if(v1==v2 and c1==c2) return true;
        return false;
        
    }
};

int main()
{
    string w1,w2;
    w1 = "abc";
    w2 = "bca";
    Solution s;
    cout<<s.closeStrings(w1,w2);
    return 0;
}