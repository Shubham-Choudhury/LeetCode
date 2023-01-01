// Link: https://leetcode.com/problems/design-movie-rental-system/

#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem
{
    struct HASH
    {
        size_t operator()(const pair<int, int> &x) const
        {
            return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
        }
    };

public:
    int n;
    vector<set<pair<int, int>>> M;
    set<vector<int>> R;
    unordered_map<pair<int, int>, int, HASH> P;
    MovieRentingSystem(int N, vector<vector<int>> &entries)
    {
        n = N;
        M.resize(10001);
        P.reserve(1000000);
        for (auto x : entries)
        {
            int s = x[0], m = x[1], p = x[2];
            M[m].insert({p, s});
            P[{m, s}] = p;
        }
    }

    vector<int> search(int movie)
    {
        vector<int> res;
        int cnt = 5;
        for (auto x : M[movie])
        {
            if (cnt == 0)
                break;
            res.push_back(x.second);
            cnt--;
        }
        return res;
    }

    void rent(int shop, int movie)
    {
        int price = P[{movie, shop}];
        M[movie].erase(M[movie].find({price, shop}));
        R.insert({price, shop, movie});
    }

    void drop(int shop, int movie)
    {
        int price = P[{movie, shop}];
        M[movie].insert({price, shop});
        R.erase({price, shop, movie});
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> res;
        int cnt = 5;
        for (auto x : R)
        {
            if (cnt == 0)
                break;
            res.push_back(vector<int>({x[1], x[2]}));
            cnt--;
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> entries = {{0, 1, 5}, {1, 2, 6}, {0, 3, 7}, {1, 3, 8}, {2, 3, 9}};
    MovieRentingSystem *obj = new MovieRentingSystem(4, entries);
    vector<int> param_1 = obj->search(1);
    obj->rent(0, 1);
    obj->drop(0, 1);
    vector<vector<int>> param_4 = obj->report();
    return 0;
}