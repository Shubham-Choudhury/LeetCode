// Link: https://leetcode.com/problems/online-majority-element-in-subarray/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


class MajorityChecker {
public:
    vector<int> arr;
    unordered_map<int, vector<int>> mp;
    MajorityChecker(vector<int>& arr) {
        this->arr = arr;
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        for(int i = 0; i < 20; i++) {
            int idx = left + rand() % (right - left + 1);
            int num = arr[idx];
            int l = lower_bound(mp[num].begin(), mp[num].end(), left) - mp[num].begin();
            int r = upper_bound(mp[num].begin(), mp[num].end(), right) - mp[num].begin();
            if(r - l >= threshold) return num;
        }
        return -1;
    }
};

int main()
{
    vector<int> arr = {1,1,2,2,1,1};
    MajorityChecker s(arr);
    cout << s.query(0, 5, 4) << endl;
    cout << s.query(0, 3, 3) << endl;
    cout << s.query(2, 3, 2) << endl;
    return 0;
}
