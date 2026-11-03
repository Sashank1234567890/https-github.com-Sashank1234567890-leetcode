class Solution {
public:
    vector<int> par, sz, prime;

    int find(int x) {
        if (par[x] == x) return x;

        return par[x] = find(par[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);

        par[b] = a;
        sz[a] += sz[b];
    }

    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);

        par.resize(n + 1);
        sz.assign(n + 1, 1);
        prime.assign(n + 1, 1);

        iota(par.begin(), par.end(), 0);

        // Sieve of Eratosthenes
        prime[0] = prime[1] = 0;

        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = 0;
                }
            }
        }

        // Build adjacency list
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Union adjacent non-prime nodes
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            if (!prime[u] && !prime[v]) {
                unite(u, v);
            }
        }

        long long ans = 0;

        // Process every prime node
        for (int i = 1; i <= n; i++) {
            if (!prime[i]) continue;

            long long sum = 0;

            for (int child : adj[i]) {
                if (!prime[child]) {
                    long long s = sz[find(child)];

                    ans += s;
                    ans += sum * s;

                    sum += s;
                }
            }
        }

        return ans;
    }
};