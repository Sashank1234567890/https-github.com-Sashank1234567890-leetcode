class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {

        if (sx == fx && sy == fy && t == 1)
            return false;

        int need = max(abs(fx - sx), abs(fy - sy));

        return t >= need;
    }
};