class Solution {
public:

    vector<vector<long long>> dp;
    vector<vector<vector<int>>> best;
    vector<int> nxt;

    long long solve(int cnt, int i, vector<vector<int>>& time) {

        int n = time.size();

        if (cnt == 4 || i == n) {
            best[cnt][i].clear();
            return 0;
        }

        if (dp[cnt][i] != -1)
            return dp[cnt][i];

        // Skip
        long long skip = solve(cnt, i + 1, time);
        vector<int> skipAns = best[cnt][i + 1];

        // Take
        long long take =
            time[i][2] + solve(cnt + 1, nxt[i], time);

        vector<int> takeAns;
        takeAns.push_back(time[i][3]);

        for (int x : best[cnt + 1][nxt[i]])
            takeAns.push_back(x);

        sort(takeAns.begin(), takeAns.end());

        if (take > skip ||
            (take == skip && takeAns < skipAns)) {

            best[cnt][i] = takeAns;
            return dp[cnt][i] = take;
        }

        best[cnt][i] = skipAns;
        return dp[cnt][i] = skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<vector<int>> time;

        for (int i = 0; i < n; i++) {

            time.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(time.begin(), time.end());

        // next non-overlapping interval
        nxt.resize(n);

        for (int i = 0; i < n; i++) {

            int l = i + 1;
            int r = n;

            while (l < r) {

                int mid = l + (r - l) / 2;

                if (time[mid][0] > time[i][1])
                    r = mid;
                else
                    l = mid + 1;
            }

            nxt[i] = l;
        }

        dp.assign(5, vector<long long>(n, -1));

        best.resize(5);

        for (int i = 0; i < 5; i++)
            best[i].resize(n + 1);

        solve(0, 0, time);

        return best[0][0];
    }
};