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
        vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector< int>> &queries)
        {
            UnionFind uf(n);

            for (int i = 1; i < n; i++)
            {
                if (nums[i] - nums[i - 1] <= maxDiff)
                    uf.Union(i, i - 1);
            }

            vector<bool> ans;

            for (auto &q: queries)
            {
                ans.push_back(uf.find(q[0]) == uf.find(q[1]));
            }

            return ans;
        }
};