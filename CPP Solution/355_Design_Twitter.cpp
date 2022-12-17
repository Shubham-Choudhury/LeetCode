// Link: https://leetcode.com/problems/design-twitter/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

class Twitter {
private:
    vector<pair<int,int>>posts;
    unordered_map<int, unordered_map<int, int>>follows;
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        posts.push_back(make_pair(userId, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>feed;
        int count = 0;
        for(int i = posts.size() - 1; i >= 0 && count < 10; i--)
            if(posts[i].first == userId || follows[userId][posts[i].first])
                feed.push_back(posts[i].second), count++;
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId][followeeId] = 0;
    }
};

int main()
{
    Twitter twitter;
    twitter.postTweet(1, 5);
    twitter.getNewsFeed(1);
    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    twitter.getNewsFeed(1);
    twitter.unfollow(1, 2);
    twitter.getNewsFeed(1);
    return 0;
}
