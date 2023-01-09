// Link: https://leetcode.com/problems/reduce-array-size-to-the-half/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[arr[i]]++;
        }
        vector<int> v;
        for (auto it = m.begin(); it != m.end(); it++) {
            v.push_back(it->second);
        }
        sort(v.begin(), v.end(), greater<int>());
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += v[i];
            ans++;
            if (sum >= n / 2) {
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3,3,3,3,5,5,5,2,2,7};
    cout << sol.minSetSize(arr) << endl;
    return 0;
}
