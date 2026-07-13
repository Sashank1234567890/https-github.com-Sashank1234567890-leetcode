class Solution
{
    public:

        int target;
    int cnt;

    int dfs(int curr, int parent,
        unordered_map<int, vector < int>> &adj,
        vector<int> &nums)
    {

        int sum = nums[curr];

        for (int &ngbr: adj[curr])
        {
            if (ngbr != parent)
            {
                sum += dfs(ngbr, curr, adj, nums);
            }
        }

        if (sum == target)
        {
            cnt++;
            return 0;
        }

        return sum;
    }

    int componentValue(vector<int> &nums, vector<vector< int>> &edges)
    {

        int n = nums.size();

        unordered_map<int, vector < int>> adj;

        int total = 0;
        for (int x: nums)
            total += x;

        for (auto &e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int comp = n; comp >= 1; comp--)
        {

            if (total % comp)
                continue;

            target = total / comp;
            cnt = 0;

            if (dfs(0, -1, adj, nums) == 0 && cnt == comp)
                return comp - 1;
        }

        return 0;
    }
};