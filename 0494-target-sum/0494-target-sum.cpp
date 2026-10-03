class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;
        
        target = abs(target);

        for(const int& x : nums) {
            sum += x;
        }
        
        if((sum + target)%2 != 0)//subset differce eqaul to x wla question hi to hai
            return 0;
        
        int s1 = (sum + target)/2;

        vector<int> prev(s1 + 1, 0), curr(s1 + 1, 0);

        
        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s1; j++) {   
                int skip = 0;
                int take = 0;

                skip = prev[j];

                if (nums[i-1] <= j) {
                    take = prev[j - nums[i-1]];
                }
\
                curr[j] = (skip + take);
            }

            prev = curr;
        }

        return prev[s1];
    }
};

