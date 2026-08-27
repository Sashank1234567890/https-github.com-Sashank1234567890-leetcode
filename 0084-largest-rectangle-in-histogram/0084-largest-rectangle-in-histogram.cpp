class Solution
{
    public:
        int largestRectangleArea(vector<int> &arr)
        {
            int n = arr.size();
            stack<int> st;
            int ans = 0;

            for (int i = 0; i < n; i++)
            {
                while (!st.empty() && arr[st.top()] > arr[i])
                {
                    int index = st.top();
                    st.pop();

                    int right = i;
                    int left;

                    if (!st.empty())
                        left = st.top();
                    else
                        left = -1;

                    int width = right - left - 1;

                    ans = max(ans, arr[index] * width);
                }

                st.push(i);
            }

            while (!st.empty())
            {
                int index = st.top();
                st.pop();

                int right = n;
                int left;

                if (!st.empty())
                    left = st.top();
                else
                    left = -1;

                int width = right - left - 1;

                ans = max(ans, arr[index] *width);
            }

            return ans;
        }
};