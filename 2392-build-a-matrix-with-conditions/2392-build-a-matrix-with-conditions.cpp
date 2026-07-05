class Solution {
public:

    vector<int> topoSort(int k, vector<vector<int>>& conditions) {

        vector<vector<int>> adj(k + 1);
        vector<int> indegree(k + 1);

        for(auto &e : conditions) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        queue<int> q;

        for(int i = 1; i <= k; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> order;

        while(!q.empty()) {

            int u = q.front();
            q.pop();

            order.push_back(u);

            for(int v : adj[u]) {

                indegree[v]--;

                if(indegree[v] == 0)
                    q.push(v);
            }
        }

        if(order.size() != k)
            return {};

        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        vector<int> rowOrder = topoSort(k, rowConditions);

        if(rowOrder.empty())
            return {};

        vector<int> colOrder = topoSort(k, colConditions);

        if(colOrder.empty())
            return {};

        vector<int> rowPos(k + 1);
        vector<int> colPos(k + 1);

        for(int i = 0; i < k; i++) {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));

        for(int i = 1; i <= k; i++) {
            ans[rowPos[i]][colPos[i]] = i;
        }

        return ans;
    }
};