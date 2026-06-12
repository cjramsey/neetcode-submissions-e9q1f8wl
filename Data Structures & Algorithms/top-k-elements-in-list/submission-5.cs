public class Solution {
    public int[] TopKFrequent(int[] nums, int k) {
        Dictionary<int, int> counts = new();
        List<int>[] freq = new List<int>[nums.Length + 1];
        for (int i = 0; i < freq.Length; i++) {
            freq[i] = new List<int>();
        }

        foreach (int n in nums) {
            if (!counts.ContainsKey(n)) {
                counts[n] = 0;
            }
            ++counts[n];
        }

        foreach (var (n, c) in counts) {
            freq[c].Add(n);
        }

        int[] res = new int[k];
        int index = 0;
        for (int i = freq.Length - 1; i >= 0; --i) {
            foreach (int n in freq[i]) {
                res[index] = n;
                ++index;
                if (index == k) {
                    return res;
                }
            }
        }
        return res;
    }
}
