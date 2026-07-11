class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<int>& vis,
             int &nodes, int &edges) {

        vis[u] = 1;
        nodes++;
        edges += adj[u].size();

        for(int v : adj[u]) {
            if(!vis[v])
                dfs(v, adj, vis, nodes, edges);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n,0);

        int ans=0;

        for(int i=0;i<n;i++) {

            if(vis[i]) continue;

            int nodes=0;
            int edgeCnt=0;

            dfs(i,adj,vis,nodes,edgeCnt);

            edgeCnt/=2;

            if(edgeCnt==nodes*(nodes-1)/2)
                ans++;
        }

        return ans;
    }
};