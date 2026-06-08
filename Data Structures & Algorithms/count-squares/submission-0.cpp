class CountSquares {
public:
    CountSquares() { 
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        ++pts[x][y];
    }
    
    int count(vector<int> point) {
        int res = 0;
        int x1 = point[0];
        int y1 = point[1];
        for (auto&[y2, count] : pts[x1]) {
            int side = y2 - y1;
            if (side == 0) {
                continue;
            }
            int x3 = x1 + side;
            int x4 = x1 - side;
            res += count * pts[x3][y1] * pts[x3][y2];
            res += count * pts[x4][y1] * pts[x4][y2];
        }
        return res;
    }

private:
    unordered_map<int, unordered_map<int, int>> pts;
    // outer key is x, inner key is y, value is frequency
};
