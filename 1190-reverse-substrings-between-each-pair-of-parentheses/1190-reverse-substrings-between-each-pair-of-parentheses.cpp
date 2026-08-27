class Solution
{
public:

    void reverse(string &s)
    {
        int i = 0, j = s.length() - 1;

        while(i < j)
        {
            swap(s[i++], s[j--]);
        }
    }

    string reverseParentheses(string s)
    {
        stack<string> st;
        string t = "";

        for(char x : s)
        {
            if(x == '(')
            {
                st.push(t);
                t.clear();
            }

            else if(x == ')')
            {
                string r = t;
                t.clear();

                reverse(r);

                if(!st.empty())
                {
                    string u = st.top();
                    st.pop();

                    t = u + r;
                }
                else
                {
                    t = r;
                }
            }

            else
            {
                t.push_back(x);
            }
        }

        return t;
    }
};