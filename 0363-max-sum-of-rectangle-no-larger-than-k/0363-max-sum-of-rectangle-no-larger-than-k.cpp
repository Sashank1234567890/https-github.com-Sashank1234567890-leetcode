class Solution
{
    public:
        int maxSumSubmatrix(vector<vector < int>> &matrix, int k)
        {

            int m = matrix.size();
            int n = matrix[0].size();

            int ans = INT_MIN;

            for (int left = 0; left < n; left++)
            {

                vector<int> temp(m, 0);

                for (int right = left; right < n; right++)
                {

                    for (int row = 0; row < m; row++)
                        temp[row] += matrix[row][right];

                    set<int> st;
                    st.insert(0);

                    int prefix = 0;

                    for (int x: temp)
                    {

                        prefix += x;

                        auto it = st.lower_bound(prefix - k);

                        if (it != st.end())
                            ans = max(ans, prefix - *it);

                        st.insert(prefix);
                    }
                }
            }

            return ans;
        }
};