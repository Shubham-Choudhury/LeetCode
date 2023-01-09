// Link: https://leetcode.com/problems/validate-binary-tree-nodes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                cnt[leftChild[i]]++;
            }
            if (rightChild[i] != -1) {
                cnt[rightChild[i]]++;
            }
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 0) {
                if (root != -1) {
                    return false;
                }
                root = i;
            }
        }
        if (root == -1) {
            return false;
        }
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(root);
        vis[root] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (leftChild[u] != -1) {
                if (vis[leftChild[u]]) {
                    return false;
                }
                q.push(leftChild[u]);
                vis[leftChild[u]] = true;
            }
            if (rightChild[u] != -1) {
                if (vis[rightChild[u]]) {
                    return false;
                }
                q.push(rightChild[u]);
                vis[rightChild[u]] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<int> leftChild = {1, -1, 3, -1};
    vector<int> rightChild = {2, -1, -1, -1};
    cout << sol.validateBinaryTreeNodes(n, leftChild, rightChild) << endl;
    return 0;
}
