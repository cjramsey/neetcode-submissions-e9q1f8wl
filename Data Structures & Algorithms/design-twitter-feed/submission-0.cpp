class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    int count;

    Twitter() : count{0} {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({count, tweetId});
        if (tweets[userId].size() > 10) {
            tweets[userId].erase(tweets[userId].begin());
        }
        --count;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        follows[userId].insert(userId);  
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        if (follows[userId].size() >= 10) {
            priority_queue<vector<int>> maxHeap;
            for (auto f: follows[userId]) {
                if (!tweets.count(f)) {
                    continue;
                }

                int idx = tweets[f].size() - 1;
                auto& p = tweets[f][idx];
                maxHeap.push({-p.first, p.second, f, idx - 1});
                if (maxHeap.size() > 10) {
                    maxHeap.pop();
                }
            }
            while (!maxHeap.empty()) {
                auto t = maxHeap.top();
                maxHeap.pop();
                minHeap.push({-t[0], t[1], t[2], t[3]});
            }
        }
        else {
            for (auto f : follows[userId]) {
                if (!tweets.count(f)) continue;
                int idx = tweets[f].size() - 1;
                auto &p = tweets[f][idx];
                minHeap.push({p.first, p.second, f, idx - 1});
            }
        }
        while (!minHeap.empty() && res.size() < 10) {
            auto t = minHeap.top();
            minHeap.pop();
            res.push_back(t[1]);
            int idx = t[3];
            if (idx >= 0) {
                auto &p = tweets[t[2]][idx];
                minHeap.push({p.first, p.second, t[2], idx - 1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
