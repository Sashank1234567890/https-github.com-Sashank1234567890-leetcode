class Solution
{
    public:
        int largestRectangleArea(vector<int> &arr)
        {
            int n = arr.size();
            stack<int> st;
            int ans = 0;
            int idx;
            for (int i = 0; i < n; i++)
            {
                while (!st.empty() && arr[st.top()] > arr[i])
                {
                    idx = st.top();
                    st.pop();
                    if (!st.empty())
                        ans = max(ans, arr[idx] *( i - st.top() - 1));
                    else
                        ans = max(ans, arr[idx] * i);
                }
                st.push(i);
            }
            while (!st.empty())
            {
                idx = st.top();
                st.pop();
                if (!st.empty())
                    ans = max(ans, arr[idx] *(n - st.top() - 1));
                else
                    ans = max(ans, arr[idx] *n);
            }

            return ans;
        }
};