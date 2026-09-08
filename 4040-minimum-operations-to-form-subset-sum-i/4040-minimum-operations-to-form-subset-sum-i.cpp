class Solution {
public:

    int n;
    int target;

    const int INF = 1e9;

    vector<vector<int>> dp;


    int solve(vector<int>& nums, int i, int sum)
    {
        // Required sum achieved
        if (sum == 0)
            return 0;

        // Cannot form negative sum
        if (sum < 0)
            return INF;

        // No elements left
        if (i == n)
            return INF;

        if (dp[i][sum] != -1)
            return dp[i][sum];


        // Don't take nums[i]
        int skip = solve(nums, i + 1, sum);


        // Take nums[i] after multiplication
        int takeMultiply = INF;

        int val = nums[i];
        int cost = 0;

        while (val <= sum)
        {
            int next = solve(
                nums,
                i + 1,
                sum - val
            );

            if (next != INF)
            {
                takeMultiply = min(
                    takeMultiply,
                    cost + next
                );
            }

            // Prevent integer overflow
            if (val > sum / 2)
                break;

            val *= 2;
            cost++;
        }


        // Take nums[i] after division
        int takeDivide = INF;

        val = nums[i];
        cost = 0;

        while (val > 0)
        {
            int next = solve(
                nums,
                i + 1,
                sum - val
            );

            if (next != INF)
            {
                takeDivide = min(
                    takeDivide,
                    cost + next
                );
            }

            val /= 2;
            cost++;
        }


        return dp[i][sum] =
            min({
                skip,
                takeMultiply,
                takeDivide
            });
    }


    int minOperations(vector<int>& nums, int sum)
    {
        n = nums.size();
        target = sum;

        dp.assign(
            n,
            vector<int>(sum + 1, -1)
        );

        int ans = solve(nums, 0, sum);

        return ans == INF ? -1 : ans;
    }
};