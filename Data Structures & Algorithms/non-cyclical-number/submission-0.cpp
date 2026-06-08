class Solution {
public:
    unordered_set<int> seen;
    bool isHappy(int n) {
        if (n == 1) {
            return true;
        }
        if (seen.contains(n)) {
            return false;
        }
        seen.insert(n);

        int res = 0;
        while (n > 0) {
            res += pow(n % 10, 2);
            n /= 10;
        }
        
        return isHappy(res);
    }
};
