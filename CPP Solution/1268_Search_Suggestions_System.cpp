// Link: https://leetcode.com/problems/search-suggestions-system/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        string prefix = "";
        for (char c : searchWord)
        {
            prefix += c;
            vector<string> temp;
            for (string s : products)
            {
                if (s.find(prefix) == 0)
                {
                    temp.push_back(s);
                    if (temp.size() == 3)
                        break;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{
    vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord = "mouse";
    Solution *obj = new Solution();
    vector<vector<string>> ans = obj->suggestedProducts(products, searchWord);
    for (auto v : ans)
    {
        for (auto s : v)
            cout << s << " ";
        cout << endl;
    }
    return 0;
}

    