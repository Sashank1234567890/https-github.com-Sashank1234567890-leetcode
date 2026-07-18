class Solution {
public:
    int findGCD(vector<int>& arr) {
        return gcd(ranges::min(arr),ranges::max(arr));
    }
};