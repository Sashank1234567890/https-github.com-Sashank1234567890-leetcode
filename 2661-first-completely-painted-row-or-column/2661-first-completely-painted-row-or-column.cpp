class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, int> row;
        unordered_map<int, int> col;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                int x = mat[i][j];

                row[x] = i;
                col[x] = j;
            }
        }

        vector<int> rcount(m, 0);
        vector<int> ccount(n, 0);

        for(int i = 0; i < arr.size(); i++) {

            int x = arr[i];

            int r = row[x];
            int c = col[x];

            rcount[r]++;
            ccount[c]++;

            if(rcount[r] == n || ccount[c] == m)
                return i;
        }

        return -1;
    }
};