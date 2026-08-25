class Solution {
public:
    struct Hash {
        int operator()(const pair<int,int>& p) const {
            return p.first * 100000 + p.second;
        }
    };

    int countServers(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int,int>> v;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1)
                    v.push_back({i,j});
            }
        }

        unordered_set<pair<int,int>, Hash> st;

        for(int i = 0; i < v.size(); i++) {

            for(int j = i + 1; j < v.size(); j++) {

                if(v[i].first == v[j].first ||
                   v[i].second == v[j].second) {

                    st.insert(v[i]);
                    st.insert(v[j]);
                }
            }
        }

        return st.size();
    }
};