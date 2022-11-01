// Link: https://leetcode.com/problems/next-greater-element-i/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++){
            int j = 0;
            while(nums2[j] != nums1[i])
                j++;
            while(j < nums2.size() && nums2[j] <= nums1[i])
                j++;
            if(j == nums2.size())
                res.push_back(-1);
            else
                res.push_back(nums2[j]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> res = s.nextGreaterElement(nums1, nums2);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}