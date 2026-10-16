class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;

        sort(nums.begin(), nums.end());
        int i = 0, j = 1, n = nums.size(), ans = 0;

        while (j < n) {
            if (i == j || nums[j] - nums[i] < k) {
                j++;
            } else if (nums[j] - nums[i] > k) {
                i++;
            } else {
                ans++;
                int a = nums[i], b = nums[j];

                while (i < n && nums[i] == a) i++;
                while (j < n && nums[j] == b) j++;
            }
        }

        return ans;
    }
};