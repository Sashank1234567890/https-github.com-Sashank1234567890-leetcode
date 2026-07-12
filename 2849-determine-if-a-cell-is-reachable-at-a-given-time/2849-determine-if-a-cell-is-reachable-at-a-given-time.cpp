class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {

        int row = abs(fx - sx);
        int col = abs(fy - sy);

        int diagonal = min(row, col);

        row -= diagonal;
        col -= diagonal;

        int steps = diagonal + row + col;

        if (steps > t)
            return false;

        if (sx == fx && sy == fy && t == 1)
            return false;

        return true;
    }
};