class Solution {
public:

    unordered_map<int, vector<int>> adj;
    vector<int> ans;

    void dfs(int node, int parent){

        ans.push_back(node);

        for(int next : adj[node]){

            if(next != parent)
                dfs(next,node);
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {

        for(auto &x : adjacentPairs){

            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int start;

        for(auto &x : adj){

            if(x.second.size()==1){

                start=x.first;
                break;
            }
        }

        dfs(start,-1000000001);

        return ans;
    }
};