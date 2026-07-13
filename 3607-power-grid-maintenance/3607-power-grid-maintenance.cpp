class Solution
{
    public:

        vector<int> parent, sz;
    vector<set < int>> comp;

    int Find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = Find(parent[x]);
    }

    void Union(int x, int y)
    {

        int px = Find(x);
        int py = Find(y);

        if (px == py)
            return;

        if (sz[px] < sz[py])
            swap(px, py);

        parent[py] = px;
        sz[px] += sz[py];

        if (comp[px].size() < comp[py].size())
            swap(comp[px], comp[py]);

        for (int node: comp[py])
            comp[px].insert(node);

        comp[py].clear();
    }

    vector<int> processQueries(int c, vector<vector < int>> &connections,
        vector<vector < int>> &queries)
    {

        parent.resize(c + 1);
        sz.assign(c + 1, 1);
        comp.resize(c + 1);

        for (int i = 1; i <= c; i++)
        {
            parent[i] = i;
            comp[i].insert(i);
        }

        for (auto &edge: connections)
            Union(edge[0], edge[1]);

        vector<int> ans;

        for (auto &q: queries)
        {

            int type = q[0];
            int node = q[1];

            int par = Find(node);

            if (type == 1)
            {

                if (comp[par].count(node))
                    ans.push_back(node);
                else if (!comp[par].empty())
                    ans.push_back(*comp[par].begin());
                else
                    ans.push_back(-1);
            }
            else
            {

                comp[par].erase(node);
            }
        }

        return ans;
    }
};