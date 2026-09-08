class Solution {
public:
    int n;
    const int INF = 1e9;

    vector<vector<int>> dp;
    vector<vector<pair<int, int>>> options;

    vector<pair<int, int>> getValues(int x, int sum)
    {
        map<int, int> mp;

        int val = x;
        int divCost = 0;

        while (val > 0)
        {
            int cur = val;
            int mulCost = 0;

            while (cur <= sum)
            {
                int cost = divCost + mulCost;

                if (!mp.count(cur))
                    mp[cur] = cost;
                else
                    mp[cur] = min(mp[cur], cost);

                if (cur > sum / 2)
                    break;

                cur *= 2;
                mulCost++;
            }

            val /= 2;
            divCost++;
        }

        vector<pair<int, int>> ans;

        for (auto &[value, cost] : mp)
            ans.push_back({value, cost});

        return ans;
    }

    int solve(vector<int>& nums, int i, int sum)
    {
        if (sum == 0)
            return 0;

        if (i == n)
            return INF;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        int skip = solve(nums, i + 1, sum);

        int take = INF;

        for (auto &[value, cost] : options[i])
        {
            if (value <= sum)
            {
                int next = solve(
                    nums,
                    i + 1,
                    sum - value
                );

                if (next != INF)
                {
                    take = min(
                        take,
                        cost + next
                    );
                }
            }
        }

        return dp[i][sum] = min(skip, take);
    }

    int minOperations(vector<int>& nums, int sum)
    {
        n = nums.size();

        dp.assign(
            n,
            vector<int>(sum + 1, -1)
        );

        options.resize(n);

        for (int i = 0; i < n; i++)
        {
            options[i] = getValues(nums[i], sum);
        }

        int ans = solve(nums, 0, sum);

        return ans == INF ? -1 : ans;
    }
};