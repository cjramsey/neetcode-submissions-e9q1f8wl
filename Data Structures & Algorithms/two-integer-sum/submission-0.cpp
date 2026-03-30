class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexes{};

        int i{0};
        for (const auto& n: nums)
        {
            if (indexes.contains(target - n))
            {
                return vector{indexes[target - n], i};
            }
            indexes[n] = i;
            ++i;
        } 
    }
};
