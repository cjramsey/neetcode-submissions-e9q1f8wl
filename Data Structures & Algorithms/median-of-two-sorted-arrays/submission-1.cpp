class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int half = (total + 1) / 2;

        int l = 0;
        int r = m;
        int i, j;
        int l1, l2, r1, r2;
        while (l <= r) {
            i = (l + r) / 2;
            j = half - i;

            r1 = i < m ? nums1[i] : std::numeric_limits<int>::max();
            r2 = j < n ? nums2[j] : std::numeric_limits<int>::max();
            l1 = i > 0 ? nums1[i - 1] : std::numeric_limits<int>::min();
            l2 = j > 0 ? nums2[j - 1] : std::numeric_limits<int>::min();
            
            if (l1 <= r2 && l2 <= r1) {
                if (total % 2 != 0) {
                    return max(l1, l2);
                }
                else {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }
            else if (l1 > r2) {
                r = i - 1;
            }
            else {
                l = i + 1;
            }
        }
        return -1;
    }
};
