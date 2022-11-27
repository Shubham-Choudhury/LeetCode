// Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }
        string result = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL) {
                result += "null,";
            } else {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return NULL;
        }
        vector<string> nodes;
        int i = 0;
        while (i < data.size()) {
            int j = i;
            while (j < data.size() && data[j] != ',') {
                j++;
            }
            nodes.push_back(data.substr(i, j - i));
            i = j + 1;
        }
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int index = 1;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (nodes[index] != "null") {
                node->left = new TreeNode(stoi(nodes[index]));
                q.push(node->left);
            }
            index++;
            if (nodes[index] != "null") {
                node->right = new TreeNode(stoi(nodes[index]));
                q.push(node->right);
            }
            index++;
        }
        return root;
    }
};

int main() {
    Codec codec;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    string data = codec.serialize(root);
    cout << data << endl;
    TreeNode* result = codec.deserialize(data);
    cout << result->val << endl;
    return 0;
}