#include <algorithm>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto it = ranges::max_element(piles.begin(), piles.end());
        int upper = *it;
        int l = 1, r = upper;
        while (l < r) {
            int m = midpoint(l, r);
            int hrs = 0;
            for (double p: piles) {
                hrs += ceil(p / m);
            }
            if (hrs <= h) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return r;
    }
};
