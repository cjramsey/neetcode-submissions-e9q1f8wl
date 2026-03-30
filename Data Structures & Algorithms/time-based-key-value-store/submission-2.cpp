class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        stores[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (stores.empty() || !stores.contains(key)) {
            return "";
        }

        auto& vec = stores[key];
        int l = 0;
        int r = vec.size() - 1;
        string res = "";
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (vec[m].first <= timestamp) {
                res = vec[m].second;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return res;
    }

private:
    std::unordered_map<string, vector<pair<int, string>>> stores;
};
