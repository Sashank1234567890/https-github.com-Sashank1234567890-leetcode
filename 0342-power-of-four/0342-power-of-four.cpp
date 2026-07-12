class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;

        double x = log2(n);

        if (x != floor(x))
            return false;

        return ((int)x % 2 == 0);
    }
};