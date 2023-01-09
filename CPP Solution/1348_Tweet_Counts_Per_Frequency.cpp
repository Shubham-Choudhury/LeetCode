// Link: https://leetcode.com/problems/tweet-counts-per-frequency/

#include <bits/stdc++.h>
using namespace std;

class TweetCounts {
public:
    unordered_map<string, vector<int>> mp;
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int n = mp[tweetName].size();
        int interval = 0;
        if (freq == "minute") {
            interval = 60;
        } else if (freq == "hour") {
            interval = 3600;
        } else {
            interval = 86400;
        }
        vector<int> ans((endTime - startTime) / interval + 1, 0);
        for (int i = 0; i < n; i++) {
            int time = mp[tweetName][i];
            if (time >= startTime && time <= endTime) {
                ans[(time - startTime) / interval]++;
            }
        }
        return ans;
    }
};

int main() {
    TweetCounts* obj = new TweetCounts();
    obj->recordTweet("tweet3", 0);
    obj->recordTweet("tweet3", 60);
    obj->recordTweet("tweet3", 10);
    vector<int> param_2 = obj->getTweetCountsPerFrequency("minute", "tweet3", 0, 59);
    vector<int> param_3 = obj->getTweetCountsPerFrequency("minute", "tweet3", 0, 60);
    for (int i = 0; i < param_2.size(); i++) {
        cout << param_2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < param_3.size(); i++) {
        cout << param_3[i] << " ";
    }
    cout << endl;
    return 0;
}
