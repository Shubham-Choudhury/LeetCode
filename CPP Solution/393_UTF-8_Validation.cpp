// Link: https://leetcode.com/problems/utf-8-validation/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool validUtf8(vector<int> &data)
    {
        int L = data.size();
        int index = 0;
        while (index < L)
        {
            int num = data[index];
            int count = 0;
            if (num & 0x80)
            {
                while (num & 0x80)
                {
                    count++;
                    num <<= 1;
                }
                if (count == 1 || count > 4)
                {
                    return false;
                }
                for (int i = 1; i < count; i++)
                {
                    index++;
                    if (index >= L)
                    {
                        return false;
                    }
                    if ((data[index] & 0xC0) != 0x80)
                    {
                        return false;
                    }
                }
            }
            index++;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> data = {197, 130, 1};
    cout << s.validUtf8(data) << endl;
    return 0;
}
