class Solution
{
    public:
        int diagonalSum(vector<vector < int>> &mat)
        {
            int n = mat.size();
            int sum = 0;
            for (int i = 0; i < n; i++)
            {

                sum += mat[i][i] + mat[i][n - i - 1] *(i == n - i - 1 ? 0 : 1);
            }
            return sum;
        }
};