// Link: https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> result;
        result.push_back(label); //taking bottom up approach, so the label itself must be included 
        int height=log2(label); //height of label from root
        
        while(height!=0){
            int left=pow(2,height-1); // rank of left limit of the previous level 
            int right=pow(2,height)-1;// rank of right limit of the previous level
            label=left+(right-label/2);// The previous level is sorted in different order than current one.
                                       //So the new label is adjusted accordingly
            result.push_back(label);  //newly found label is appened to result
            height--;
        }
        
        reverse(result.begin(),result.end()); //required top to down, so the array is reversed. 
        return result;
    }
};

int main()
{
    Solution sol;
    int label;
    cin >> label;
    vector<int> ans = sol.pathInZigZagTree(label);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
