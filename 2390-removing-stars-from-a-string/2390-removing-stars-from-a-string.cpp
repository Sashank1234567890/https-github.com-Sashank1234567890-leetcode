class Solution
{
    public:
        string removeStars(string s)
        {
            stack<char> st;
            for (char &x: s)
            {
                if (x == '*')
                {
                    st.pop();
                }
                else
                {
                    st.push(x);
                }
            }
            int n = st.size();
            s=string (n, 'a');
            int i = n - 1;
            while (!st.empty())
            {
                s[i] = st.top();
                st.pop();
                i--;
            }
            return s;
        }
};