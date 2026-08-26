class Solution
{
    public:

        int numSubmat(vector<vector < int>> &mat)
        {
            int m = mat.size();
            int n = mat[0].size();

            vector<int> height(n, 0);
            int result = 0;

            for (int row = 0; row < m; row++)
            {
                for (int col = 0; col < n; col++)
                {
                    if (mat[row][col] == 1)
                        height[col]++;
                    else
                        height[col] = 0;
                }

                stack<int> st;
                vector<int> sum(n, 0);

                for (int col = 0; col < n; col++)
                {
                    while (!st.empty() && height[st.top()] >= height[col])
                        st.pop();

                    if (!st.empty())
                    {
                        int prev = st.top();

                        sum[col] = sum[prev] + height[col] *(col - prev);
                    }
                    else
                    {
                        sum[col] = height[col] *(col + 1);
                    }

                    result += sum[col];

                    st.push(col);
                }
            }

            return result;
        }
};