#include <array>
#include <vector>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq{};
        const int s = nums.size();
        vector<vector<int>> buckets{};
        buckets.resize(s);

        for (const auto& n: nums)
        {
            if (!freq.contains(n)) 
                freq[n] = 0;

            ++freq[n];
        }

        for (const auto& entry: freq)
        {
            buckets[entry.second - 1].push_back(entry.first);
        }

        vector<int> res{};
        for (auto i = buckets.rbegin(); i != buckets.rend(); ++i)
        {
            res.insert(res.end(), (*i).begin(), (*i).end());
            k -= (*i).size();

            if (k <= 0) return res;
        }
        return {};
    }  
};
