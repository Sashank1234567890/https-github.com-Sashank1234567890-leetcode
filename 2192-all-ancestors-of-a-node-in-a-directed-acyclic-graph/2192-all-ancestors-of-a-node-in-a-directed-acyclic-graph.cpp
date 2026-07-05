class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<set<int>> st(n);

        unordered_map<int, vector<int>> adj;
        vector<int> in(n);

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            in[v]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(in[i] == 0)
                q.push(i);
        }

        while(!q.empty()) {

            int u = q.front();
            q.pop();

            for(int v : adj[u]) {

                in[v]--;

                for(int x : st[u])
                    st[v].insert(x);

                st[v].insert(u);

                if(in[v] == 0)
                    q.push(v);
            }
        }

        vector<vector<int>> result(n);

        for(int i = 0; i < n; i++) {
            for(int x : st[i])
                result[i].push_back(x);
        }

        return result;
    }
};