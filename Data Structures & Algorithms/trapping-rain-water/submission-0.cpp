class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix;
        vector<int> suffix;

        int prefix_max = 0;
        for (auto it = height.begin(); it != height.end(); ++it)
        {
            prefix.push_back(prefix_max);
            prefix_max = max(prefix_max, *it);
        }
        int suffix_max = 0;
        for (auto it = height.rbegin(); it != height.rend(); ++it)
        {
            suffix.push_back(suffix_max);
            suffix_max = max(suffix_max, *it);
        }
        reverse(suffix.begin(), suffix.end());

        int res = 0;        
        for (int i = 1; i < height.size() - 1; ++i)
        {
            res += max(min(prefix[i], suffix[i]) - height[i], 0);
        }
        return res;
    }
};
