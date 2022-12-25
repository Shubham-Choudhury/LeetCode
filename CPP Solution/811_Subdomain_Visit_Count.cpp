// Link: https://leetcode.com/problems/subdomain-visit-count/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> cnt;
        for (string cpdomain : cpdomains) {
            int i = cpdomain.find(' ');
            int n = stoi(cpdomain.substr(0, i));
            string domain = cpdomain.substr(i + 1);
            for (int i = 0; i < domain.size(); i++) {
                if (domain[i] == '.') {
                    cnt[domain.substr(i + 1)] += n;
                }
            }
            cnt[domain] += n;
        }
        vector<string> ans;
        for (auto p : cnt) {
            ans.push_back(to_string(p.second) + " " + p.first);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> cpdomains = {"9001 discuss.leetcode.com"};
    vector<string> ans = sol.subdomainVisits(cpdomains);
    for (string s : ans) {
        cout << s << endl;
    }
    return 0;
}