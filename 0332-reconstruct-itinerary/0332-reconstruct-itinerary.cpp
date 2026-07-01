class Solution {
public:
    unordered_map<string, multiset<string>> adj;
    vector<string> ans;

    void dfs(string src) {

        while (!adj[src].empty()) {

            auto it = adj[src].begin();

            string next = *it;

            adj[src].erase(it);

            dfs(next);
        }

        ans.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (auto &x : tickets)
            adj[x[0]].insert(x[1]);

        dfs("JFK");

        reverse(ans.begin(), ans.end());

        return ans;
    }
};