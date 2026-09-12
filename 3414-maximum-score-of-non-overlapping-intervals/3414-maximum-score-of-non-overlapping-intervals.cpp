class Solution
{
    public:
        vector<vector < long long>> dp;
    vector<vector<vector< int>>> best;

    vector<int> maximumWeight(vector<vector < int>> &intervals)
    {
        int n = intervals.size();
        vector<vector < int>> time;

        for (int i = 0; i < n; i++)
        {
            time.push_back({ intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i });
        }

        sort(time.begin(), time.end());

        vector<int> nxt(n);

        for (int i = 0; i < n; i++)
        {
            int l = i + 1, r = n;

            while (l < r)
            {
                int mid = l + (r - l) / 2;

                if (time[mid][0] > time[i][1])
                    r = mid;
                else
                    l = mid + 1;
            }

            nxt[i] = l;
        }

        dp.assign(5, vector < long long > (n + 1, 0));
        best.assign(5, vector<vector < int>> (n + 1));

        for (int cnt = 3; cnt >= 0; cnt--)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                long long skip = dp[cnt][i + 1];
                vector<int> skipAns = best[cnt][i + 1];

                long long take = time[i][2] + dp[cnt + 1][nxt[i]];

                vector<int> takeAns;
                takeAns.push_back(time[i][3]);

                for (int &x: best[cnt + 1][nxt[i]])
                    takeAns.push_back(x);

                sort(takeAns.begin(), takeAns.end());

                if (take > skip || (take == skip && takeAns < skipAns))
                {
                    dp[cnt][i] = take;
                    best[cnt][i] = takeAns;
                }
                else
                {
                    dp[cnt][i] = skip;
                    best[cnt][i] = skipAns;
                }
            }
        }

        return best[0][0];
    }
};