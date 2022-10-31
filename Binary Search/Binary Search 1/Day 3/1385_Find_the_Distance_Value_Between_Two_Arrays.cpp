// Link: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/?envType=study-plan&id=binary-search-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        for(int i = 0; i < arr1.size(); i++){
            bool flag = true;
            for(int j = 0; j < arr2.size(); j++){
                if(abs(arr1[i] - arr2[j]) <= d){
                    flag = false;
                    break;
                }
            }
            if(flag) res++;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr1 = {4,5,8}, arr2 = {10,9,1,8};
    cout << s.findTheDistanceValue(arr1, arr2, 2) << endl;
    return 0;
}