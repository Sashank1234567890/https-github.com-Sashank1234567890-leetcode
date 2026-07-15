class Solution {
public:
    int minChanges(vector<int>& nums, int k) {

        vector<int> diff(k + 2, 0);

        int n = nums.size();

        for (int i = 0; i < n / 2; i++) {

            int a = nums[i];
            int b = nums[n - 1 - i];

            int currDiff = abs(a - b);

            int minDiff = 0;

            int maxDiff = max({a, b, k - a, k - b});

            // initially 2 moves
            diff[0] += 2;
            diff[k + 1] -= 2;

            // 1 move interval [minDiff ... maxDiff]
            diff[minDiff]-=1;
            diff[maxDiff + 1]+=1;

            // 0 move at currDiff
            diff[currDiff]-=1;
            diff[currDiff + 1]+=1;
        }

        int ans = INT_MAX;
        int curr = 0;

        for (int d = 0; d <= k; d++) {

            curr += diff[d];

            ans = min(ans, curr);
        }

        return ans;
    }
};