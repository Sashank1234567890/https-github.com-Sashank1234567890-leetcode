class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> vec(mx - mn + 1, 0);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int d = abs(nums[i] - nums[j]);
                vec[d]++;
            }
        }

        for(int d = 0; d <= mx - mn; d++) {
            k -= vec[d];
            if(k <= 0)
                return d;
        }

        return -1;
    }
};