// Link: https://leetcode.com/problems/add-to-array-form-of-integer/?envType=study-plan&id=programming-skills-ii

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res;
        int i = A.size() - 1;
        while (i >= 0 || K > 0) {
            if (i >= 0) {
                K += A[i];
                i--;
            }
            res.push_back(K % 10);
            K /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    Solution s;
    vector<int> A = {1,2,0,0};
    int K = 34;
    vector<int> res = s.addToArrayForm(A, K);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}