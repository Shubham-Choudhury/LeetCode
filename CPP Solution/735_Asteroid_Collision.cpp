// Link: https://leetcode.com/problems/asteroid-collision/?envType=study-plan&id=level-2

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) {
                    st.pop();
                }
                if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                } else if (st.top() == abs(asteroids[i])) {
                    st.pop();
                }
            }
        }
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution obj;
    vector<int> asteroids = {5, 10, -5};
    vector<int> res = obj.asteroidCollision(asteroids);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}