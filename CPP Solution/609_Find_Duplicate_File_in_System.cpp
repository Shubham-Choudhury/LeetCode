// Link: https://leetcode.com/problems/find-duplicate-file-in-system/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> content_to_paths;
        for (auto& path : paths) {
            int i = 0;
            while (path[i] != ' ') {
                i++;
            }
            string dir = path.substr(0, i);
            i++;
            while (i < path.size()) {
                int j = i;
                while (path[j] != '(') {
                    j++;
                }
                string file_name = path.substr(i, j - i);
                j++;
                i = j;
                while (path[j] != ')') {
                    j++;
                }
                string content = path.substr(i, j - i);
                content_to_paths[content].push_back(dir + "/" + file_name);
                i = j + 2;
            }
        }
        vector<vector<string>> res;
        for (auto& it : content_to_paths) {
            if (it.second.size() > 1) {
                res.push_back(it.second);
            }
        }
        return res;
    }
};

int main(void) {
    Solution sol;
    vector<string> paths = {
        "root/a 1.txt(abcd) 2.txt(efgh)",
        "root/c 3.txt(abcd)",
        "root/c/d 4.txt(efgh)",
        "root 4.txt(efgh)"
    };
    vector<vector<string>> res = sol.findDuplicate(paths);
    for (auto& row : res) {
        for (auto& file : row) {
            cout << file << " ";
        }
        cout << endl;
    }
    return 0;
}
