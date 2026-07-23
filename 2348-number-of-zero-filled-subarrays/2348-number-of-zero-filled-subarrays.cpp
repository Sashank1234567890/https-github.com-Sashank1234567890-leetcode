class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        long long ans = 0;
        int i = 0;

        for (int j = 0; j < nums.size(); j++) {

            if (nums[j] != 0) {
                i = j + 1;
            } else {
                ans += j - i + 1;
            }
        }

        return ans;
    }
};