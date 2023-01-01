// Link: https://leetcode.com/problems/single-threaded-cpu/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef pair<int, int> pa; // making the symbol as freq used
    // using priority queue  and sorting the tasks vector
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        vector<int> ans;
        long long int prestime = 1; // starting time

        priority_queue<pa, vector<pa>, greater<pa>> pq; // min priority_queue
        int n = tasks.size();
        if (n == 0)
            return ans;
        for (int i = 0; i < n; i++) // storing index to each of the tasks so even after sorting we
            tasks[i].push_back(i);  // can keep track of the indices for ans vector.
        sort(tasks.begin(), tasks.end(), [](vector<int> &v1, vector<int> &v2)
             {
                 return v1[0] < v2[0]; // sorting them wrt enquetime i.e index=0.
             });
        int i = 0;
        while (i < n || !pq.empty())
        {
            int flag1 = 0, flag2 = 0;
            while (i < n && prestime >= tasks[i][0]) // this loop pushes the tasks in the pq till my
            {                                        // prestime>=enquetime of task

                pq.push(make_pair(tasks[i][1], tasks[i][2])); // pushing only the processing_time
                i++;                                          // and the index in pq.
                flag1 = 1;
            }

            if (!pq.empty()) // this block picks the least available processing_time task from
            {                // pq and inc the prestime and updates the ans vector.
                auto it = pq.top();
                pq.pop();
                prestime += it.first;
                flag2 = 1;
                ans.push_back(it.second);
            }
            if (!flag1 && !flag2)       // this block runs when the control doesn't go inside any of the
                prestime = tasks[i][0]; // above two blocks which means that CPU is idle.
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> tasks = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
    Solution obj;
    vector<int> ans = obj.getOrder(tasks);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}