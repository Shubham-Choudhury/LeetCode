// Link: https://leetcode.com/problems/check-if-n-and-its-double-exist/?envType=study-plan&id=binary-search-i

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        bool ans = false;

        for(int i=0;i<arr.size();++i){		
            for(int j=0;j<arr.size();++j){
                if(i!=j && ((arr[i]%2==0 && arr[i]==2*arr[j]) || (arr[i]%2==0 && arr[i]/2==arr[j]))){
                    ans = true;
                    break;
                }
            }
        }
         return ans;
    }
};

int main() {
    Solution s;
    vector<int> arr = {10,2,5,3};
    cout << s.checkIfExist(arr) << endl;
    return 0;
}