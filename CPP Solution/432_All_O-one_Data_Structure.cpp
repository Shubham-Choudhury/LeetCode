// Link: https://leetcode.com/problems/all-oone-data-structure/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <list>
#include <unordered_set>
using namespace std;

struct Countode {
    int val;
    unordered_multiset<string> strset;
};
class AllOne {
    list<Countode> m_list;
    unordered_map<string, list<Countode>::iterator> m_hash;
public:
    void inc(string key) {
        auto iter = m_hash.find(key);
        if (iter == m_hash.end())
        {
            if (m_list.empty() || m_list.front().val != 1)
                m_list.push_front(Countode{1,{}});
            m_hash[key] = m_list.begin();
            m_list.front().strset.insert(key);
            return;
        }
        auto org_iter = iter->second;
        auto val = org_iter->val;
        auto list_iter = next(org_iter);
        if (list_iter == m_list.end() || list_iter->val != val + 1)
            list_iter = m_list.insert(list_iter, Countode{val + 1, {}});
        list_iter->strset.insert(key);
        iter->second = list_iter;
        auto str_iter = org_iter->strset.find(key);
        org_iter->strset.erase(str_iter);
        if (org_iter->strset.empty())
            m_list.erase(org_iter);
    }
    void dec(string key) {
        auto iter = m_hash.find(key);
        if (iter == m_hash.end())
            return;
        auto org_iter = iter->second;
        auto list_iter = prev(org_iter);
        auto val = org_iter->val;
        if (val > 1)
        {
            if (org_iter == m_list.begin() || list_iter->val != val - 1)
                list_iter = m_list.insert(org_iter, Countode{val - 1, {}});
            m_hash[key] = list_iter;
            list_iter->strset.insert(key);
        }else
            m_hash.erase(iter);
        auto str_iter = org_iter->strset.find(key);
        org_iter->strset.erase(str_iter);
        if (org_iter->strset.empty())
            m_list.erase(org_iter);
        
    }
    string getMaxKey() {
        return m_list.empty() ? "": *(m_list.back().strset.begin());
    }
    string getMinKey() {
        return m_list.empty() ? "": *(m_list.front().strset.begin());
    }
};

int main() {
    AllOne ao;
    ao.inc("hello");
    ao.inc("world");
    ao.inc("hello");
    cout << ao.getMaxKey() << endl;
    cout << ao.getMinKey() << endl;
    ao.dec("hello");
    cout << ao.getMaxKey() << endl;
    cout << ao.getMinKey() << endl;
    return 0;
}