// https://leetcode.com/problems/flood-fill/?envType=study-plan&id=graph-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor != newColor) {
            dfs(image, sr, sc, oldColor, newColor);
        }
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor) {
        if(image[sr][sc] == oldColor) {
            image[sr][sc] = newColor;
            if(sr >= 1) {
                dfs(image, sr - 1, sc, oldColor, newColor);
            }
            if(sc >= 1) {
                dfs(image, sr, sc - 1, oldColor, newColor);
            }
            if(sr + 1 < image.size()) {
                dfs(image, sr + 1, sc, oldColor, newColor);
            }
            if(sc + 1 < image[0].size()) {
                dfs(image, sr, sc + 1, oldColor, newColor);
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> result = s.floodFill(image, 1, 1, 2);
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}