// Link: https://leetcode.com/problems/delete-duplicate-folders-in-system/

#include <bits/stdc++.h>
using namespace std;

 class Solution {
public:
    struct Node {
        map<string,Node*> m; 
        pair<long long,long long> h_p;  
        string name; 
        void add(const vector<string>& path, int i) {
            if(i == path.size()) {
                return;
            }
            const string& str = path[i];
            if(!m.count(str)) {
                m[str] = new Node();
                m[str]->name = str; 
            }
            m[str]->add(path,i+1);
        }
        
        static long long h(const string& str, long long hash) {
            long long ret = 0; 
            for(char ch : str) {
                ret = ret * 27 + ((ch - 'a')+1);
                ret %= hash; 
            }
            return ret; 
        }
        
        pair<long long,long long> hash(map<pair<long long,long long>,int>& counter) {
            const long long hash_1 = 80000023; 
            const long long hash_2 = 90000059;
            const long long a = 100003; 
            const long long b = 300007; 
            int i = 0; 
            int j = 1; 
            long long ret1 = 0, ret2 = 0; 
            for(auto& p : m) {
                auto tmp = p.second->hash(counter);
                ret1 = ret1 * i + tmp.first; 
                ret1 %= hash_1; 
                ret2 = ret2 * j + tmp.second; 
                ret2 %= hash_2; 
                i += 3;
                j += 5;
            }
            h_p = {ret1,ret2}; 
            if(m.size()) {
                counter[h_p]++; 
            }
            ret1 = (ret1 * a + h(name,70000043)) % hash_1;
            ret2 = (ret2 * b + h(name,60000049)) % hash_2;
            return {ret1,ret2};
        }
        
        bool check(const vector<string>& path, int i,map<pair<long long,long long>,int>& counter) {
            if(i == path.size()) {
                return true; 
            }
            auto& str = path[i];
            auto child = m[str];
            int count = counter[child->h_p];
            if(count > 1) {
                return false; 
            }
            return child->check(path,i+1,counter);
            
        }
        
    };
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node();
        for(auto& path : paths) {
            root->add(path,0);
        }
        map<pair<long long,long long>,int> counter; 
        root->hash(counter);
        vector<vector<string>> ret; 
        for(auto& path : paths) {
            if(root->check(path,0,counter)) {
                ret.push_back(path);
            }
        }
        return ret; 
    }
};

int main()
{
    Solution s;
    vector<vector<string>> paths = {{"a"}, {"c"}, {"d"}, {"a", "b"}, {"c", "b"}, {"d", "a"}};
    vector<vector<string>> ans = s.deleteDuplicateFolder(paths);
    for (auto path : ans)
    {
        for (auto folder : path)
        {
            cout << folder << " ";
        }
        cout << endl;
    }
    return 0;
}