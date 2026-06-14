public class Solution {
    public int[] TwoSum(int[] numbers, int target) {
        int l = 0;
        int r = numbers.Count() - 1;

        while (l < r) {
            int total = numbers[l] + numbers[r];

            if (total < target) {
                ++l;
            }
            else if (total > target) {
                --r;
            }
            else {
                return new int[] {1 + l, 1 + r};
            }
        }
        return new int[0];
    }
}
