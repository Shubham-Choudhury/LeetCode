// Link: https://leetcode.com/problems/validate-ip-address/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        if(IP.find('.')!=string::npos)
        {
            if(IP[IP.length()-1]=='.')
                return "Neither";
            int count = 0;
            for(int i=0; i<IP.length(); i++)
            {
                if(IP[i]=='.')
                    count++;
            }
            if(count!=3)
                return "Neither";
            vector<string> v;
            string tmp = "";
            for(int i=0; i<IP.length(); i++)
            {
                if(IP[i]=='.')
                {
                    v.push_back(tmp);
                    tmp = "";
                }
                else
                    tmp += IP[i];
            }
            v.push_back(tmp);
            if(v.size()!=4)
                return "Neither";
            for(int i=0; i<v.size(); i++)
            {
                if(v[i].length()==0 || v[i].length()>3)
                    return "Neither";
                if(v[i].length()>1 && v[i][0]=='0')
                    return "Neither";
                int num = 0;
                for(int j=0; j<v[i].length(); j++)
                {
                    if(v[i][j]<'0' || v[i][j]>'9')
                        return "Neither";
                    num = num*10 + (v[i][j]-'0');
                }
                if(num<0 || num>255)
                    return "Neither";
            }
            return "IPv4";
        }
        else if(IP.find(':')!=string::npos)
        {
            if(IP[IP.length()-1]==':')
                return "Neither";
            int count = 0;
            for(int i=0; i<IP.length(); i++)
            {
                if(IP[i]==':')
                    count++;
            }
            if(count!=7)
                return "Neither";
            vector<string> v;
            string tmp = "";
            for(int i=0; i<IP.length(); i++)
            {
                if(IP[i]==':')
                {
                    v.push_back(tmp);
                    tmp = "";
                }
                else
                    tmp += IP[i];
            }
            v.push_back(tmp);
            if(v.size()!=8)
                return "Neither";
            for(int i=0; i<v.size(); i++)
            {
                if(v[i].length()==0 || v[i].length()>4)
                    return "Neither";
                for(int j=0; j<v[i].length(); j++)
                {
                    if(v[i][j]>='0' && v[i][j]<='9')
                        continue;
                    else if(v[i][j]>='a' && v[i][j]<='f')
                        continue;
                    else if(v[i][j]>='A' && v[i][j]<='F')
                        continue;
                    else
                        return "Neither";
                }
            }
            return "IPv6";
        }
        else
            return "Neither";
    }
};


int main()
{
    Solution s;
    string IP = "172.16.254.1";
    cout<<s.validIPAddress(IP)<<endl;
    return 0;
}
