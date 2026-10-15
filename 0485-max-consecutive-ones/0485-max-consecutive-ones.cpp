class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        int mx = 0;

        while (j < n) {
            if (nums[j] == 1) {
                mx = max(mx, j - i + 1);
                j++;
            } else {
                j++;
                i = j;
            }
        }

        return mx;
    }
};