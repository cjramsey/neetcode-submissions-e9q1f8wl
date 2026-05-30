class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int MAX = numeric_limits<int>::max();
        int MIN = numeric_limits<int>::min();

        while (x != 0) {
            if ((res > MAX / 10) || (res < MIN / 10)) {
                return 0;
            }
            if (res == MAX / 10 && x % 10 > MAX % 10) {
                return 0;
            }
            if (res == MIN / 10 && x % 10 < MIN % 10) {
                return 0;
            }
            res *= 10;
            res += (x % 10);
            x /= 10;
        }
        return res;
    }
};
