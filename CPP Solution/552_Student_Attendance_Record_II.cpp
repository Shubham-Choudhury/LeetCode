// Link: https://leetcode.com/problems/student-attendance-record-ii/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        //They represent a valid sequence at length i with the different states:
        //lla: ending with LL and has a A
        //la : ending with L  and has a A
        //pa : ending with P  and has a A
        //a  : ending with A
        //ll : ending with LL and has no A
        //l  : ending with L  and has no A
        //p  : ending with P  and has no A
        long long lla = 0, la = 0, pa = 0, a = 1, ll = 0, l = 1, p = 1, base = 1000000007;
        for (int i = 2; i <= n ; ++i)
        {
            long long pa_last = pa, p_last = p;
            pa += (lla + la + a) % base;
            lla = la;
            la = (pa_last + a) % base;
            a = ll + l + p;
            p += (ll + l) % base;
            ll = l;
            l = p_last;
        }
        return (lla + la + pa + a + ll+ l + p) % base ;
    }
};

int main()
{
    Solution obj;
    int n;
    int res;

    n = 2;
    res = obj.checkRecord(n);
    cout << res << endl;

    n = 1;
    res = obj.checkRecord(n);
    cout << res << endl;

    n = 10101;
    res = obj.checkRecord(n);
    cout << res << endl;

    return 0;
}
