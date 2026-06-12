public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        int n = nums.Length;
        int[] res = Enumerable.Repeat(1, n).ToArray();

        int pre = 1;
        for (int i = 0; i < n; ++i) {
            res[i] *= pre;
            pre *= nums[i];
        }

        int post = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= post;
            post *= nums[i];
        }

        return res;
    }
}
