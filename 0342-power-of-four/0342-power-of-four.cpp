class Solution {
public:
    bool isPowerOfFour(int n) {
        //(4^x-1)%3==0;
        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};
