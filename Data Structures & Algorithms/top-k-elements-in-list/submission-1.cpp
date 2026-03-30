class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> temp(nums.size() + 1);
        map<int, int, greater<int>> freq;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i)
        {
            ++freq[nums[i]];
        }

        for (auto i = freq.begin(); i != freq.end(); ++i)
        {
            temp[i->second].push_back(i->first);
        }

        for (int i = temp.size() - 1; i > 0; --i)
        {
            for (int j = 0; j < temp[i].size(); ++j)
            {
                result.push_back(temp[i][j]);
                --k;
                if (k == 0) return result;
            }
        }
        return result;
    }
};
