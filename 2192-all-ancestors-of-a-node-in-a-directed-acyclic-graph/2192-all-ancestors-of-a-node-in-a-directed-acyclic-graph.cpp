class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<unordered_set<int>> st(n);

        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()) {

            int u = q.front();
            q.pop();

            for(int v : adj[u]) {

                indegree[v]--;

                for(int x : st[u])
                    st[v].insert(x);

                st[v].insert(u);

                if(indegree[v] == 0)
                    q.push(v);
            }
        }

        vector<vector<int>> result(n);

        for(int i = 0; i < n; i++) {

            for(int x : st[i])
                result[i].push_back(x);

            sort(result[i].begin(), result[i].end());
        }

        return result;
    }
};