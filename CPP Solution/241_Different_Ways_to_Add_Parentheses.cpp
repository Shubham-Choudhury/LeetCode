// Link: https://leetcode.com/problems/different-ways-to-add-parentheses/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        if (input[i] == '+') {
                            result.push_back(left[j] + right[k]);
                        } else if (input[i] == '-') {
                            result.push_back(left[j] - right[k]);
                        } else {
                            result.push_back(left[j] * right[k]);
                        }
                    }
                }
            }
        }
        if (result.empty()) {
            result.push_back(stoi(input));
        }
        return result;
    }
};

int main() {
    string input = "2*3-4*5";
    vector<int> result = Solution().diffWaysToCompute(input);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    return 0;
}
