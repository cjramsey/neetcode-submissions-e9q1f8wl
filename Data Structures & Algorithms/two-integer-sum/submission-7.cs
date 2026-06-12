public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        var seen = new Dictionary<int, int>();
        var n = nums.Length;

        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];
            if (seen.ContainsKey(diff)) {
                return new int[] {seen[diff], i};
            }
            else seen[nums[i]] = i;
        }
        return null;
    }
}
