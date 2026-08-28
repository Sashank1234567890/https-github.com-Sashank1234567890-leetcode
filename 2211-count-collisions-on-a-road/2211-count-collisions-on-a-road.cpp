class Solution
{
public:
    int countCollisions(string dir)
    {
        stack<char> st;
        int cnt = 0;

        for(char ch : dir)
        {
            if(st.empty())
            {
                st.push(ch);
            }
            else
            {
                if(ch == 'L' && st.top() == 'S')
                {
                    st.push('S');
                    cnt += 1;
                }
                else if(ch == 'S' && st.top() == 'R')
                {
                    int x = 0;

                    while(!st.empty() && st.top() == 'R')
                    {
                        st.pop();
                        x++;
                    }

                    cnt += x;

                    while(x--)
                        st.push('S');

                    st.push('S');
                }
                else if(ch == 'L' && st.top() == 'R')
                {
                    int x = 0;

                    while(!st.empty() && st.top() == 'R')
                    {
                        st.pop();
                        x++;
                    }

                    cnt += x + 1;

                    while(x--)
                        st.push('S');
                }
                else
                {
                    st.push(ch);
                }
            }
        }

        return cnt;
    }
};