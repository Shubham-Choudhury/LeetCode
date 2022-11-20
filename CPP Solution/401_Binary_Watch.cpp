// Link: https://leetcode.com/problems/binary-watch/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (bitset<10>(i << 6 | j).count() == num) {
                    result.push_back(to_string(i) + (j < 10 ? ":0" : ":") + to_string(j));
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> result = s.readBinaryWatch(1);
    for (auto time : result) {
        cout << time << endl;
    }
    return 0;
}