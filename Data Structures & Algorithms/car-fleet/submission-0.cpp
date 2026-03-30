class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> stats;
        for (int i = 0; i < position.size(); ++i) {
            stats.push_back({position[i], speed[i]});
        }
        sort(stats.begin(), stats.end());

        int res = 0;
        double current_time = 0;

        for (int i = stats.size() - 1; i >= 0; --i) {
            double time = (target - stats[i].first) / static_cast<double>(stats[i].second);
            if (time > current_time) {
                res += 1;
                current_time = time;
            }
        }

        return res;
    }
};
