class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<int> prevRow(n), currRow(n);

        for (int i = 0; i < m; i++) {

            currRow = img[i];          // Save original current row

            for (int j = 0; j < n; j++) {

                int sum = 0, cnt = 0;

                // Previous row
                if (i > 0) {
                    for (int c = max(0, j - 1); c <= min(n - 1, j + 1); c++) {
                        sum += prevRow[c];
                        cnt++;
                    }
                }

                // Current row (original)
                for (int c = max(0, j - 1); c <= min(n - 1, j + 1); c++) {
                    sum += currRow[c];
                    cnt++;
                }

                // Next row
                if (i + 1 < m) {
                    for (int c = max(0, j - 1); c <= min(n - 1, j + 1); c++) {
                        sum += img[i + 1][c];
                        cnt++;
                    }
                }

                img[i][j] = sum / cnt;
            }

            prevRow = currRow;
        }

        return img;
    }
};