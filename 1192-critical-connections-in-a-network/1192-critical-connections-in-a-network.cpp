
class Solution {
    public:
void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis,vector<vector<int>>&bridges, vector<int>& disc,vector<int>& low,int& timer) {

        vis[node] = 1;
        disc[node] = low[node] = timer++;

        for (int neigh : adj[node]) {
            if (neigh == parent) continue;

          
            if (vis[neigh]) {
                low[node] = min(low[node], low[neigh]);
            }
            else {
             

                dfs(neigh, node, adj, vis,bridges, disc, low, timer);

                low[node] = min(low[node], low[neigh]);

                if (low[neigh] > disc[node]) {
                    vector<int>temp(2);
                    temp[0]=node;
                    temp[1]=neigh;
                    bridges.push_back(temp);
                }
            }
        }
    }
      
    vector<vector<int>> criticalConnections(int V, vector<vector<int>>& edges) {
          vector<vector<int>> adj(V);
          vector<vector<int>> bridges;

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(V, 0);
        vector<int> disc(V, -1);
        vector<int> low(V, -1);

        int timer = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis,bridges, disc, low, timer);
            }
        }

        return bridges;
    }
};