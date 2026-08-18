class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> cnt;

        for(int i = 0; i < n; i++) {
            cnt[nums[i]]++;
        }

        if(k == n) {
            return ranges::max(nums);
        }

        if(k == 1) {
            int ans = -1;

            for(auto it : cnt) {
                if(it.second == 1) {
                    ans = max(ans, it.first);
                }
            }

            return ans;
        }

        int ans = -1;

        if(cnt[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        if(cnt[nums[n-1]] == 1) {
            ans = max(ans, nums[n-1]);
        }

        return ans;
    }
};