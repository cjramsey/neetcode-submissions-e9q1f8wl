public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> seen = new();
        for (int i = 0; i < nums.Length; ++i) {
            if (seen.ContainsKey(target - nums[i])) {
                return [seen[target - nums[i]], i];
            }
            seen[nums[i]] = i;
        }
        return [];
    }
}
