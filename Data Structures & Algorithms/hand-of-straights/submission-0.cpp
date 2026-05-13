class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        unordered_map<int, int> count;
        for (int n: hand) {
            ++count[n];
        }

        sort(hand.begin(), hand.end());
        for (int n: hand) {
            if (count[n] == 0) {
                continue;
            }
            for (int i = 0; i < groupSize; ++i) {
                if (count[n + i] == 0) {
                    return false;
                }
                --count[n + i];
            }
        }
        return true;
    }
};
