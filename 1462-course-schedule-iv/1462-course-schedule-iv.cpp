class Solution {
public:
    // Perform DFS and mark prerequisites for each node
    bool dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int src, int target) {
        visited[src] = true;

        if (src == target) {
            return true;
        }

        bool isPrerequisite = false;
        for (auto adjNode : adj[src]) {
            if (!visited[adjNode]) {
                isPrerequisite = isPrerequisite || dfs(adj, visited, adjNode, target);
            }
        }
        return isPrerequisite;
    }

    void preprocess(int numCourses, unordered_map<int, vector<int>>& adjList, vector<vector<bool>>& isPrerequisite) {
        for (int u = 0; u < numCourses; u++) {
            for (int v = 0; v < numCourses; v++) {
                if (u != v) {
                    vector<bool> visited(numCourses, false);
                    if (dfs(adjList, visited, u, v)) {
                        isPrerequisite[u][v] = true;
                    }
                }
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
        for (auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
        }

        vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));
        preprocess(numCourses, adjList, isPrerequisite);

        int Q = queries.size();
        vector<bool> result(Q);

        for(int i = 0; i < Q; i++) {
            int u = queries[i][0]; //source.
            int v = queries[i][1]; //Dest.

            result[i] = isPrerequisite[u][v];
        }

        return result;
    }
};

