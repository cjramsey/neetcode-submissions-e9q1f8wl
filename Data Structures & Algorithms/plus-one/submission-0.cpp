class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry = 1;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            int digit = (*it + carry) % 10;
            res.push_back(digit);
            carry = (*it + carry) / 10;
        }
        if (carry) { 
            res.push_back(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
