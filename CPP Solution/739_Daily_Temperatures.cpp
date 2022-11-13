// Link: https://leetcode.com/problems/daily-temperatures/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && T[st.top()] < T[i]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = s.dailyTemperatures(T);
    for(auto it:ans) cout << it << " ";
    cout << endl;
    return 0;
}
