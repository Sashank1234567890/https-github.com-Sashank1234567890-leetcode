class Solution
{
    public:
        bool parseBoolExpr(string exp)
        {
            stack<char> st;
            stack<char> sym;
            for (char x: exp)
            {
                if (x == '!' || x == '&' || x == '|')
                {
                    sym.push(x);
                }
                else if (x == ')')
                {
                    char sy = sym.top();
                    sym.pop();

                    bool ans = 0;
                    if (sy == '&')
                        ans = 1;
                    while (st.top() != '(')
                    {
                        char y = st.top();
                        st.pop();
                        bool z;
                        if (y == 'f')
                        {
                            z = 0;
                        }
                        else
                        {
                            z = 1;
                        }
                        if (sy == '!')
                        {
                            ans = !z;
                        }
                        else if (sy == '&')
                        {
                            ans &= z;
                        }
                        else
                        {
                            ans |= z;
                        }
                    }
                    st.pop();
                    if (ans == 0)
                    {
                        st.push('f');
                    }
                    else
                    {
                        st.push('t');
                    }
                }
                else if(x==','){
                    continue;
                }
                else
                {
                    st.push(x);
                }
            }
            return st.top() == 'f' ? false : true;
        }
};