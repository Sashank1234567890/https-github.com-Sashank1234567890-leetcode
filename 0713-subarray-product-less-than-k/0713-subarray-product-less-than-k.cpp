class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if (k <= 1)
            return 0;

        int n = nums.size();

        vector<double> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + log(nums[i]);

        double target = log(k);
        int ans = 0;
        const double eps = 1e-9;

        for (int i = 0; i < n; i++) {

            int l = i + 1;
            int r = n;
            int last = i;

            while (l <= r) {

                int mid = l + (r - l) / 2;

                if (prefix[mid] - prefix[i] < target - eps) {
                    last = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            ans += last - i;
        }

        return ans;
    }
};