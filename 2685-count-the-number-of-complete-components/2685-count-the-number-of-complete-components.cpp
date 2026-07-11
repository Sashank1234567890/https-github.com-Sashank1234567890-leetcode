    class UnionFind
    {
        public:
            vector<int> parent, rank;

        UnionFind(int n)
        {
            parent.resize(n);
            rank.assign(n, 0);

            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x)
        {
            if (parent[x] == x)
                return x;

            return parent[x] = find(parent[x]);
        }

        void Union(int x, int y)
        {
            int px = find(x);
            int py = find(y);

            if (px == py)
                return;

            if (rank[px] > rank[py])
                parent[py] = px;
            else if (rank[px] < rank[py])
                parent[px] = py;
            else
            {
                parent[py] = px;
                rank[px]++;
            }
        }
    };
    class Solution
    {

        public:

            int countCompleteComponents(int n, vector<vector < int>> &edges)
            {
                vector<vector < int>> components(n);
                unordered_map<int, unordered_set < int>> mp;
                int m = edges.size();
                UnionFind uf(n);
                for (int i = 0; i < m; i++)
                {
                    int u = edges[i][0];
                    int v = edges[i][1];
                    mp[u].insert(v);
                    mp[v].insert(u);
                    uf.Union(u, v);
                }
                for (int i = 0; i < n; i++)
                {
                    uf.find(i);
                    components[uf.parent[i]].push_back(i);
                }
                int cnt = 0;
                for (int i = 0; i < n; i++)
                {
                    if (components[i].size() == 1)
                    {
                        cnt++;
                    }
                    else if (components[i].size() > 1)
                    {
                        bool complete = true;

                        for (int u: components[i])
                        {
                            for (int v: components[i])
                            {
                                if (u != v && !mp[u].contains(v))
                                {
                                    complete = false;
                                    break;
                                }
                            }

                            if (!complete)
                                break;
                        }

                        if (complete)
                            cnt++;
                    }
                }
                return cnt;
            }
    };