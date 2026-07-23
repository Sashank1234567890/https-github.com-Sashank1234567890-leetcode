class Solution
{
    public:
        vector<vector < int>> generateMatrix(int n)
        {

            vector<vector < int>> ans(n, vector<int> (n));

            int left = 0;
            int right = n - 1;
            int top = 0;
            int bottom = n - 1;

            int x = 1;

            while (left <= right && top <= bottom)
            {

                for (int j = left; j <= right; j++)
                    ans[top][j] = x , x++;
                top++;

                for (int i = top; i <= bottom; i++)
                    ans[i][right] = x , x++;
                right--;

                if (top <= bottom)
                {
                    for (int j = right; j >= left; j--)
                        ans[bottom][j] = x , x++;
                    bottom--;
                }

                if (left <= right)
                {
                    for (int i = bottom; i >= top; i--)
                        ans[i][left] = x, x++;
                    left++;
                }
            }

            return ans;
        }
};