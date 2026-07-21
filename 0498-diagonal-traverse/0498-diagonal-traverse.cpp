class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
       
        vector<int> res;
        int m = mat.size();
        int n = mat[0].size();
        for(int diag = 0; diag < m  + n -1; diag++) {
            if (diag % 2 == 0) {
                int largestRow = min(m - 1, diag);
                for (int r = largestRow; r >= 0; r--) {
                    if (diag - r < 0 || diag - r >= n) {
                        break;
                    }
                    res.push_back(mat[r][diag-r]);
                }
            } else {
                int largestCol = min(n - 1, diag);
                for (int c = largestCol; c >= 0; c--) {
                    if (diag - c < 0 || diag - c >= m) {
                        break;
                    }
                    res.push_back(mat[diag-c][c]);
                }
            }
        }
        return res;
    }
};