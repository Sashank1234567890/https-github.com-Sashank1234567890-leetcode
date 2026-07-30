class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        return min(n, 8)
             + 2 * min(max(n - 8, 0), 8)
             + 3 * min(max(n - 16, 0), 8)
             + 4 * max(n - 24, 0);
    }
};