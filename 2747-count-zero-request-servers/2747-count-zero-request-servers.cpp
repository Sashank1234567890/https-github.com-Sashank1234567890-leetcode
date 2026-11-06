class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        unordered_map<int,int> st;

        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        vector<pair<int,int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());

        int i = 0, j = 0;

        for (auto &que : q) {
            int t = que.first;
            int l = t - x;

            while (i < logs.size() && logs[i][1] <= t) {
                st[logs[i][0]]++;
                i++;
            }

            while (j < i && logs[j][1] < l) {
                st[logs[j][0]]--;

                if (st[logs[j][0]] == 0)
                    st.erase(logs[j][0]);

                j++;
            }

            ans[que.second] = n - st.size();
        }

        return ans;
    }
};