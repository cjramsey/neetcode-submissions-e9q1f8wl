#include <algorithm>
#include <ranges>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto it = upper_bound(matrix.begin(), matrix.end(), vector<int>{target},
            [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; }
        );

        if (it == matrix.begin()) return false;

        --it;

        return ranges::binary_search(*it, target);
    }
};
