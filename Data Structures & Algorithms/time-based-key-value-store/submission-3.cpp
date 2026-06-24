class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mapping;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mapping[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!mapping.contains(key)) {
            return "";
        }

        auto& v = mapping[key];
        int l = 0;
        int r = v.size() - 1;
        int index = -1;
        while (l <= r) {
            int m = midpoint(l, r);
            if (v[m].first <= timestamp) {
                index = m;
                l = m + 1;
            }
            else { 
                r = m - 1;
            }
        }
        return index == -1 ? "" : v[index].second; 
    }
};
