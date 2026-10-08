class Solution
{
    public:
        string removeOuterParentheses(string s)
        {
            int open = 0;
            int i = 0;
            deque<char> dq;

            string ans = "";
            for (char ch: s)
            {
                open += ch == ')' ? -1 : +1;
                if (open > 0)
                {
                    dq.push_back(ch);
                }
                else if (open == 0)
                {
                    dq.pop_front();
                    while (!dq.empty())
                    {
                        // cout << dq.front();
                        ans.push_back(dq.front());
                        dq.pop_front();
                    }
                }
            }

                return ans;
            }
        };