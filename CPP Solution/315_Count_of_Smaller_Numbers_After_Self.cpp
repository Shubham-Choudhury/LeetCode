// Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret, clone = nums;;
        int len = (int) nums.size();
        unordered_map<int, int> reflect;
        array.resize(len + 1);
        sort(clone.begin(), clone.end());
        for (int i = 0; i < len; ++ i)
            reflect[clone[i]] = i + 1;
        
        for (int i = len - 1; i >= 0; -- i) {
            clone[i] = query(reflect[nums[i]] - 1);
            add(reflect[nums[i]], 1);
        }
        return clone;
    }
    
private:
    vector<int> array;
    inline int lowbit(int pos) {
        return pos & -pos;
    }
    void add(int pos, int val) {
        long len = array.size();
        while (pos < len) {
            array[pos] += val;
            pos += lowbit(pos);
        }
    }
    int query(int pos) {
        int ret = 0;
        while (pos > 0) {
            ret += array[pos];
            pos -= lowbit(pos);
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {5, 2, 6, 1};
    Solution sol;
    vector<int> res = sol.countSmaller(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
