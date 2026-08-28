class Solution
{
public:
    long long minOperations(vector<vector<int>>& queries)
    {
        int mx = -1;

        for(auto &q : queries)
            mx = max(mx, q[1]);

        int cnt = 0;
        int t = mx;

        while(t)
        {
            cnt++;
            t /= 4;
        }

        vector<long long> op(cnt);

        op[0] = 3;

        for(int i = 1; i < cnt; i++)
        {
            long long size = 3LL * (1LL << (2 * i));
            op[i] = size * (i + 1);
        }

        long long total = 0;

        for(auto &q : queries)
        {
            int l = q[0];
            int r = q[1];

            int l_b = 0;
            int t = l;

            while(t >= 4)
            {
                l_b++;
                t /= 4;
            }

            int r_b = 0;
            t = r;

            while(t >= 4)
            {
                r_b++;
                t /= 4;
            }

            long long ans = 0;

            if(l_b == r_b)
            {
                ans += 1LL * (r - l + 1) * (l_b + 1);
            }
            else
            {
          
                int l_j = (1LL << (2 * (l_b + 1))) - 1;

                ans += 1LL * (l_j - l + 1) * (l_b + 1);

            
                for(int i = l_b + 1; i < r_b; i++)
                    ans += op[i];

            
                int r_i = (1LL << (2 * r_b));

                ans += 1LL * (r - r_i + 1) * (r_b + 1);
            }

            total += (ans + 1) / 2;
        }

        return total;
    }
};