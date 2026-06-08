class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() < num2.size()) {
            swap(num1, num2);
        }

        string res;
        int padding = num2.size() - 1;
        for (char d: num2) {
            string cur = mul(num1, d, padding);
            res = add(res, cur);
            --padding;
        }
        return res;
    }

private:
    string mul(string num, char digit, int padding) {
        if (digit == '0') {
            return "0";
        }
        for (int i = 0; i < padding; ++i) {
            num.push_back('0');
        }
        string res;
        int i = num.size() - 1;
        int carry = 0;
        while (i >= 0 || carry) {
            int n = (i >= 0) ? num[i] - '0' : 0;
            int total = (digit - '0') * n + carry;
            res.push_back((total % 10) + '0');
            carry = total / 10;
            --i;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string add(string num1, string num2) { 
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string res;

        while (i >= 0 || j >= 0 || carry) {
            int n1 = (i >= 0) ? num1[i] - '0' : 0;
            int n2 = (j >= 0) ? num2[j] - '0' : 0;
            int total = n1 + n2 + carry;
            res.push_back((total % 10) + '0');
            carry = total / 10;
            --i;
            --j;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
