class Solution
{
    public:
        typedef long long ll;

    int n;
    ll K;

    vector<vector<pair<int, int>>> adj;
    vector<ll> dp;
    vector<int> vis;

    ll solve(int u, int mid)
    {

        if (u == n - 1)
            return 0;

        if (vis[u])
            return dp[u];

        vis[u] = 1;

        ll ans = 1e18;

        for (auto &[v, wt]: adj[u])
        {

            if (wt < mid)
                continue;

            ll child = solve(v, mid);

            if (child != 1e18)
                ans = min(ans, child + wt);
        }

        return dp[u] = ans;
    }

    bool check(int mid)
    {

        dp.assign(n, 1e18);
        vis.assign(n, 0);

        return solve(0, mid) <= K;
    }

    int findMaxPathScore(vector<vector < int>> &edges,
        vector<bool> &online,
        long long k)
    {

        K = k;
        n = online.size();

        adj.assign(n, {});

        int mx = 0;

        for (auto &e: edges)
        {

            int u = e[0];
            int v = e[1];
            int w = e[2];

            if (online[u] && online[v])
            {
                adj[u].push_back({ v,
                    w });
                mx = max(mx, w);
            }
        }

        int l = 0;
        int r = mx;

        int ans = -1;

        while (l <= r)
        {

            int mid = l + (r - l) / 2;

            if (check(mid))
            {

                ans = mid;
                l = mid + 1;
            }
            else
            {

                r = mid - 1;
            }
        }

        return ans;
    }
};