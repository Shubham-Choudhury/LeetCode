// Link: https://leetcode.com/problems/online-election/?envType=study-plan&id=binary-search-ii

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        unordered_map<int, int> mp;
        int maxVote = 0;
        int leader = -1;
        for (int i = 0; i < n; i++) {
            mp[persons[i]]++;
            if (mp[persons[i]] >= maxVote) {
                maxVote = mp[persons[i]];
                leader = persons[i];
            }
            this->persons.push_back(leader);
            this->times.push_back(times[i]);
        }
    }
    
    int q(int t) {
        int left = 0;
        int right = times.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (times[mid] == t) {
                return persons[mid];
            } else if (times[mid] < t) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (times[left] <= t) {
            return persons[left];
        }
        return persons[left - 1];
    }

private:
    vector<int> persons;
    vector<int> times;
};

int main() {
    vector<int> persons = {0,1,1,0,0,1,0};
    vector<int> times = {0,5,10,15,20,25,30};
    TopVotedCandidate s(persons, times);
    cout << s.q(3) << endl;
    cout << s.q(12) << endl;
    cout << s.q(25) << endl;
    cout << s.q(15) << endl;
    cout << s.q(24) << endl;
    cout << s.q(8) << endl;
    return 0;
}