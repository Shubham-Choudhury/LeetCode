// Link: https://leetcode.com/problems/minimum-total-cost-to-make-arrays-unequal/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        
        const int n=nums1.size();
        long long int ans=0;
        map<int,int> freq;
        int maxFrequency=0,maxFrequencyValue=0,toSwap = 0;
        
        for(int i=0;i<n;i++){
            if(nums1[i]==nums2[i]){
                freq[nums1[i]]++;
                if(freq[nums1[i]]>maxFrequency) maxFrequencyValue=nums1[i];
                maxFrequency=max(maxFrequency,freq[nums1[i]]);
                toSwap++;
                ans+=i;
            }
        }
        
        for(int i=0;i<n;i++){
            if(maxFrequency > toSwap/2 and nums1[i]!=nums2[i] and nums1[i]!=maxFrequencyValue and nums2[i]!=maxFrequencyValue){
                ans+=i;
                toSwap++;
            }
        }
        
        if(maxFrequency > toSwap/2) return -1;
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums1{1, 7, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> nums2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << s.minimumTotalCost(nums1, nums2) << endl;
    return 0;
}