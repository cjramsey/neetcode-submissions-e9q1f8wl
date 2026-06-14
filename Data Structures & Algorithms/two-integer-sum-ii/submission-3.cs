public class Solution {
    public int[] TwoSum(int[] numbers, int target) {
        int l = 0;
        int r = numbers.Count() - 1;

        while (l < r) {
            int total = numbers[l] + numbers[r];

            if (total == target) {
                return [1 + l, 1 + r];
            }
            else if (total > target) {
                --r;
            }
            else {
                ++l;
            }
        }
        return [-1, -1];
    }
}
