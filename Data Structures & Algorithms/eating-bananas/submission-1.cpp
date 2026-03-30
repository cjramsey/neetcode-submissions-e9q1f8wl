class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1;
        long long r = accumulate(piles.begin(), piles.end(), 0LL);
        long long res = r;
        cout << r << '\n';

        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long cur = 0;
            for (const auto p: piles) {
                cur += ceil(static_cast<double>(p) / m);
            }
            cout << m << ' ' << cur << '\n';
            
            if (cur <= h) {
                res = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return res;
    }
};
