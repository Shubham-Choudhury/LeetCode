// Link: https://leetcode.com/problems/beautiful-arrangement-ii/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int>v;
     
        if(n==1)
        {
            v.push_back(1);
            return v;
        }
        int i=1,j=k+1;
        while(i<j)
        {
            v.push_back(i);
            v.push_back(j);
            i++;
            j--;
        }
        if(i==j)
            v.push_back(i);
        k=k+2;
        while(k<=n)
        {
            v.push_back(k);
            k++;
        }
        
        
       return v;     
        
    }
};

int main(void) {
    Solution sol;
    int n = 3, k = 1;
    vector<int> res = sol.constructArray(n, k);
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
