// Link: https://leetcode.com/problems/unique-number-of-occurrences/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        for (int i = 0; i < arr.size(); i++)
            count[arr[i]]++;
        
        unordered_set<int> unique;
        for (auto it = count.begin(); it != count.end(); it++)
            unique.insert(it->second);
        
        return unique.size() == count.size();
    }
};

int main()
{
    Solution sol;
    vector<int> arr = { 1, 2, 2, 1, 1, 3 };
    cout << sol.uniqueOccurrences(arr) << endl;

    return 0;
}