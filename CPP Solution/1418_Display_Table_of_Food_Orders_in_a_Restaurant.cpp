// Link: https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> displayTable(vector<vector<string>> &orders)
    {
        vector<vector<string>> res;
        map<int, map<string, int>> table;
        set<string> food;
        for (auto order : orders)
        {
            int t = stoi(order[1]);
            string f = order[2];
            table[t][f]++;
            food.insert(f);
        }
        vector<string> header;
        header.push_back("Table");
        for (auto f : food)
        {
            header.push_back(f);
        }
        res.push_back(header);
        for (auto t : table)
        {
            vector<string> row;
            row.push_back(to_string(t.first));
            for (auto f : food)
            {
                row.push_back(to_string(t.second[f]));
            }
            res.push_back(row);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> orders = {{"David", "3", "Ceviche"}, {"Corina", "10", "Beef Burrito"}, {"David", "3", "Fried Chicken"}, {"Carla", "5", "Water"}, {"Carla", "5", "Ceviche"}, {"Rous", "3", "Ceviche"}};
    vector<vector<string>> ans = sol.displayTable(orders);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
