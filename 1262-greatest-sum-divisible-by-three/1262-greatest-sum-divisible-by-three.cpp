class Solution {
public:
    int solve(int i, int remainder, vector<int>& nums, vector<vector<int>>& t) {
        if (i >= nums.size()) {
            return (remainder == 0) ? 0 : INT_MIN;
        }

        if (t[i][remainder] != -1)
            return t[i][remainder];

     
        int pick = nums[i] +
                   solve(i + 1, (remainder + nums[i]) % 3, nums, t);

       
        int notPick = solve(i + 1, remainder, nums, t);

        return t[i][remainder] = max(pick, notPick);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> t(n, vector<int>(3, -1));
        return solve(0, 0, nums, t);
    }
};
