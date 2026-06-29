class Solution {
public:
    unordered_map<string, string> parent;
    unordered_map<string, double> weight;

    string find(string x) {

        if (parent[x] == x)
            return x;

        string origParent = parent[x];

        parent[x] = find(parent[x]);

        weight[x] *= weight[origParent];

        return parent[x];
    }

    void Union(string x, string y, double value) {

        if (!parent.count(x)) {
            parent[x] = x;
            weight[x] = 1.0;
        }

        if (!parent.count(y)) {
            parent[y] = y;
            weight[y] = 1.0;
        }

        string px = find(x);
        string py = find(y);

        if (px == py)
            return;

        parent[px] = py;

        // weight[px] = px / py
        weight[px] = value * weight[y] / weight[x];
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        for (int i = 0; i < equations.size(); i++) {

            string a = equations[i][0];
            string b = equations[i][1];

            Union(a, b, values[i]);
        }

        vector<double> ans;

        for (auto &q : queries) {

            string a = q[0];
            string b = q[1];

            if (!parent.count(a) || !parent.count(b)) {
                ans.push_back(-1.0);
                continue;
            }

            string pa = find(a);
            string pb = find(b);

            if (pa != pb) {
                ans.push_back(-1.0);
            } else {
                ans.push_back(weight[a] / weight[b]);
            }
        }

        return ans;
    }
};