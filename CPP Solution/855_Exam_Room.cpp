// Link: https://leetcode.com/problems/exam-room/

#include <bits/stdc++.h>
using namespace std;

class ExamRoom
{
public:
    int n;
    set<int> s;
    ExamRoom(int _n)
    {
        n = _n;
    }

    int seat()
    {
        if (s.empty())
        {
            s.insert(0);
            return 0;
        }
        int ans = 0;
        int d = *s.begin();
        auto it = s.begin();
        auto it2 = it;
        it2++;
        for (; it2 != s.end(); it++, it2++)
        {
            int x = (*it2 - *it) / 2;
            if (x > d)
            {
                d = x;
                ans = *it + x;
            }
        }
        if (n - 1 - *s.rbegin() > d)
            ans = n - 1;
        s.insert(ans);
        return ans;
    }

    void leave(int p)
    {
        s.erase(p);
    }
};

int main()
{
    ExamRoom s(10);
    cout << s.seat() << endl;
    cout << s.seat() << endl;
    cout << s.seat() << endl;
    cout << s.seat() << endl;
    s.leave(4);
    cout << s.seat() << endl;
    return 0;
}
