public class Solution {
    public int LongestConsecutive(int[] nums) {
        HashSet<int> set = new HashSet<int>(nums);
        int res = 0;
        foreach (int n in nums) {
            if (set.Contains(n - 1)) {
                continue;
            }
            set.Add(n);
            int next = n;
            while (set.Contains(next)) {
                ++next;
            }
            res = Math.Max(res, next - n);
        }
        return res;
    }
}
