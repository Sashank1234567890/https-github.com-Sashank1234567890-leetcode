class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool Union(int u, int v) {

        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return false;

        parent[pv] = pu;
        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<int> indegree(n + 1, -1);

        int first = -1;
        int second = -1;

        // Find node having two parents
        for (int i = 0; i < n; i++) {

            int child = edges[i][1];

            if (indegree[child] == -1) {
                indegree[child] = i;
            }
            else {
                first = indegree[child];
                second = i;
                break;
            }
        }

        parent.resize(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        // Ignore second edge if two-parent case exists
        for (int i = 0; i < n; i++) {

            if (i == second)
                continue;

            int u = edges[i][0];
            int v = edges[i][1];

            if (!Union(u, v)) {

                // Only cycle
                if (first == -1)
                    return edges[i];

                // Two parents + cycle
                return edges[first];
            }
        }

        // Only two parents
        return edges[second];
    }
};