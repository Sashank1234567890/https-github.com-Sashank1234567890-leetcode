class Solution {
public:
    vector<vector<int>> directions = {
        {-1,-1},{-1,0},{-1,1},
        {0,-1},{0,0},{0,1},
        {1,-1},{1,0},{1,1}
    };

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        int m = img.size();
        int n = img[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int sum = 0;
                int cnt = 0;

                for (auto &d : directions) {
                    int r = i + d[0];
                    int c = j + d[1];

                    if (r >= 0 && r < m && c >= 0 && c < n) {
                        sum += img[r][c] % 256;   // original value
                        cnt++;
                    }
                }

                int smooth = sum / cnt;

                img[i][j] = smooth * 256 + img[i][j];
            }
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                img[i][j] /= 256;

        return img;
    }
};