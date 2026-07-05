class Solution {
public:
    int MOD = 1e9 + 7;
    int dirs[3][2] = {{1,0},{0,1},{1,1}};

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        score[n-1][n-1] = 0;
        ways[n-1][n-1] = 1;

        for(int i = n-1; i >= 0; i--) {

            for(int j = n-1; j >= 0; j--) {

                if(board[i][j] == 'X')
                    continue;

                for(int k = 0; k < 3; k++) {

                    int x = i + dirs[k][0];
                    int y = j + dirs[k][1];

                    if(x >= n || y >= n)
                        continue;

                    if(score[x][y] == -1)
                        continue;

                    int val = score[x][y];

                    if(board[i][j] >= '0' && board[i][j] <= '9')
                        val += board[i][j] - '0';

                    if(val > score[i][j]) {
                        score[i][j] = val;
                        ways[i][j] = ways[x][y];
                    }
                    else if(val == score[i][j]) {
                        ways[i][j] = (ways[i][j] + ways[x][y]) % MOD;
                    }
                }
            }
        }

        if(ways[0][0] == 0)
            return {0,0};

        return {score[0][0], ways[0][0]};
    }
};