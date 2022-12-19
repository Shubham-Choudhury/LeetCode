// Link: https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        for(auto rect : rects) {
            int area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            areas.push_back(area);
            total += area;
        }
    }
    
    vector<int> pick() {
        int randNum = rand() % total;
        int index = 0;
        while(randNum >= areas[index]) {
            randNum -= areas[index];
            index++;
        }
        vector<int> rect = rects[index];
        int x = rect[0] + randNum % (rect[2] - rect[0] + 1);
        int y = rect[1] + randNum / (rect[2] - rect[0] + 1);
        return {x, y};
    }

private:

    vector<vector<int>> rects;
    vector<int> areas;
    int total = 0;
};

int main()
{
    vector<vector<int>> rects = {{-2, -2, -1, -1}, {1, 0, 3, 0}};
    Solution s(rects);
    for(int i = 0; i < 10; i++) {
        vector<int> v = s.pick();
        cout << v[0] << " " << v[1] << endl;
    }
    return 0;
}
