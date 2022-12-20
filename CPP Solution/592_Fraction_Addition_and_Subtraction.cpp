// Link: https://leetcode.com/problems/fraction-addition-and-subtraction/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string fractionAddition(string expression)
    {
        vector<int> nu, di;
        int i = 0;
        while (i < expression.length())
        {
            bool neg = false;
            if (expression[i] == '-')
                neg = true;
            if (!isdigit(expression[i]))
                i++;
            int temp = 0;
            while (expression[i] != '/')
            {
                temp = temp * 10 + (expression[i++] - '0');
            }
            if (neg)
                temp *= -1;
            nu.push_back(temp);
            cout << temp << " , ";
            i++;
            temp = 0;
            while (i < expression.length() && isdigit(expression[i]))
            {
                temp = temp * 10 + (expression[i++] - '0');
            }
            di.push_back(temp);
            cout << temp << endl;
        }
        int lcm = findlcm(di);
        cout << "Dinominator LCM : " << lcm << endl;
        int num_sum = 0;
        for (int i = 0; i < nu.size(); i++)
        {
            num_sum += (nu[i] * (lcm / di[i]));
            // cout<<a<<" :: ";
        }
        cout << "Numerator Sum : " << num_sum << endl;
        if (num_sum == 0)
            return "0/1";
        int g = gcd(abs(num_sum), lcm);
        cout << "GCD : " << g << endl;
        num_sum /= g;
        lcm /= g;
        return to_string(num_sum) + "/" + to_string(lcm);
    }
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int findlcm(vector<int> &arr)
    {
        // Initialize result
        int ans = arr[0];

        // ans contains LCM of arr[0], ..arr[i]
        // after i'th iteration,
        for (int i = 1; i < arr.size(); i++)
            ans = (((arr[i] * ans)) /
                   (gcd(arr[i], ans)));

        return ans;
    }
};

int main(void)
{
    Solution sol;
    string expression = "-1/2+1/2";
    cout << sol.fractionAddition(expression) << endl;
    return 0;
}
