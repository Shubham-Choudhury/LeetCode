// Link: https://leetcode.com/problems/maximal-rectangle/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int res = 0;
        vector<int>heights(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            res = max(res, largestRectangleArea(heights));
        }
        return res;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int>st;
        heights.push_back(0);
        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                res = max(res, h * w);
            }
            st.push(i);
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> matrix = {{'1','0','1','0','0'},
                                   {'1','0','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','0','0','1','0'}};
    int result = solution.maximalRectangle(matrix);
    cout << result << endl;
    return 0;
}