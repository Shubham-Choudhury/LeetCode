// Link: https://leetcode.com/problems/magical-string/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        if(n == 0) return 0;
        if(n <= 3) return 1;
        vector<int> v = {1, 2, 2};
        int i = 2;
        while(v.size() < n) {
            int num = v.back() == 1 ? 2 : 1;
            for(int j = 0; j < v[i]; j++) {
                v.push_back(num);
            }
            i++;
        }
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(v[j] == 1) count++;
        }
        return count;
    }
};

int main()
{
    Solution s;
    cout << s.magicalString(6) << endl;
    return 0;
}
