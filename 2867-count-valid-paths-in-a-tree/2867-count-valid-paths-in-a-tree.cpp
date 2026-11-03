class Solution {
public:
    vector<vector<int>> adj;
    vector<int> prime, comp;
    vector<int> compSize;

    int dfs(int node, int id) {
        comp[node] = id;

        int cnt = 1;

        for (int child : adj[node]) {
            if (!prime[child] && comp[child] == 0) {
                cnt += dfs(child, id);
            }
        }

        return cnt;
    }

    long long countPaths(int n, vector<vector<int>>& edges) {
        adj.resize(n + 1);
        prime.resize(n + 1, 1);
        comp.resize(n + 1, 0);

        prime[0] = prime[1] = 0;

        // Sieve
        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                for (int j = i * 2; j <= n; j += i) {
                    prime[j] = 0;
                }
            }
        }

        // Build graph
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Find non-prime connected components
        int id = 0;

        for (int i = 1; i <= n; i++) {
            if (!prime[i] && comp[i] == 0) {
                id++;

                int sz = dfs(i, id);
                compSize.push_back(sz);
            }
        }

        long long ans = 0;

        // Process every prime node
        for (int i = 1; i <= n; i++) {
            if (!prime[i]) continue;

            long long sum = 0;

            for (int child : adj[i]) {
                if (!prime[child]) {
                    long long sz = compSize[comp[child] - 1];

                    ans += sz;
                    ans += sum * sz;// new node ko sarri old node se connect

                    sum += sz;
                }
            }
        }

        /*
            EXAMPLE 1:

            Suppose a prime node has 3 non-prime components
            with sizes:

            a = 2, b = 3, c = 4

                       2 (Prime)
                      /    |    \
                     A     B     C
                    (2)   (3)   (4)

            1. Paths from prime node to components:
               2 + 3 + 4 = 9

            2. Paths between different components:
               A and B = 2 * 3 = 6
               A and C = 2 * 4 = 8
               B and C = 3 * 4 = 12

            Total = 9 + 6 + 8 + 12 = 35


            EXAMPLE 2: LEETCODE TEST CASE

            n = 5
            edges = {{1,2}, {1,3}, {2,4}, {2,5}}

                    1
                   / \
                  2   3
                 / \
                4   5

            Prime nodes = 2, 3, 5
            Non-prime nodes = 1, 4

            Non-prime components:
                Component 1 = {1, 4}, size = 2

            Valid paths:

                1 -> 2       (one prime: 2)
                2 -> 4       (one prime: 2)
                1 -> 3       (one prime: 3)
           
            The fourth valid path is:
                1 -> 2 -> 5
                This contains TWO primes (2 and 5), so NOT valid.

            Actual valid paths:
                (1,2), (2,4), (1,3), (2,1)? 

            Remember endpoints are unordered, so (1,2) and (2,1)
            are the same path.

            Expected answer = 4.
        */

        return ans;
    }
};