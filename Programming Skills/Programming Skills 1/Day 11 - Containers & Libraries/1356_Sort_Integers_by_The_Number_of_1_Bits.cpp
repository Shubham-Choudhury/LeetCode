// Link: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        vector<pair<int, int>> v;
        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            int count = 0;
            while (num) {
                count += num & 1;
                num >>= 1;
            }
            v.push_back({count, arr[i]});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution obj;
    vector<int> ans = obj.sortByBits(arr);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}