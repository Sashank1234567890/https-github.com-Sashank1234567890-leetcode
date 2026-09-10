class Solution {
public:

    struct Hash {
        size_t operator()(const vector<int>& v) const {
            size_t h = 0;

            for(auto x : v)
                h = h * 31 + x;

            return h;
        }
    };

    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<vector<int>, int, Hash> mp;

        for(auto &row : grid){
            mp[row]++;
        }

        int cnt = 0;

        for(int j = 0; j < grid.size(); j++){
            vector<int> col;

            for(int i = 0; i < grid.size(); i++){
                col.push_back(grid[i][j]);
            }

            cnt += mp[col];
        }

        return cnt;
    }
};