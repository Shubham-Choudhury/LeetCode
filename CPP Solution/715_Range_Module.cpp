// Link: https://leetcode.com/problems/range-module/

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class RangeModule
{
public:
    map<int, int> t;

    RangeModule() { t[-1] = -1; }

    void addRange(int left, int right)
    {
        auto it = t.lower_bound(left);
        if (it == t.end() || it->first != left)
            it--;
        if (it->second >= right)
            return;
        if (left <= it->second)
            left = it->first;

        it++;
        while (true)
            if (it == t.end() || it->first > right)
            {
                t[left] = right;
                break;
            }
            else if (right <= it->second)
            {
                t[left] = it->second;
                t.erase(it->first);
                break;
            }
            else
            {
                int temp = it->first;
                it++;
                t.erase(temp);
            }
    }

    bool queryRange(int left, int right)
    {
        auto it = t.lower_bound(left);
        if (it == t.end() || it->first != left)
            it--;
        return it->second >= right;
    }

    void removeRange(int left, int right)
    {
        auto it = t.lower_bound(left);
        if (it == t.end() || it->second != left)
            it--;

        if (right < it->second)
        {
            t[right] = it->second;
            if (it->first == left)
                t.erase(left);
            else
                it->second = left;
            return;
        }

        if (it->second <= left)
            it++;
        else if (it->first < left)
        {
            it->second = left;
            it++;
        }
        else if (it->first == left)
        {
            it++;
            t.erase(left);
        }

        while (it != t.end())
        {
            if (it->first > right)
                break;
            if (right < it->second)
            {
                t[right] = it->second;
                t.erase(it->first);
                break;
            }
            int temp = it->first;
            it++;
            t.erase(temp);
        }
    }
};

int main()
{
    RangeModule s;
    s.addRange(10, 20);
    s.removeRange(14, 16);
    cout << s.queryRange(10, 14) << endl;
    cout << s.queryRange(13, 15) << endl;
    cout << s.queryRange(16, 17) << endl;
    return 0;
}
