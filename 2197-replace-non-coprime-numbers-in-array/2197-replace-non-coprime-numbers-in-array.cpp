class Solution
{
    public:
        vector<int> replaceNonCoprimes(vector<int> &nums)
        {
            vector<int> ans;
            for (int &x: nums)
            {
                ans.push_back(x);
                while (ans.size() >= 2)
                {
                    int b = ans.back();
                    ans.pop_back();
                    int gcd_ = gcd(b, ans.back());
                    if (gcd_ != 1)
                    {
                        long long mul = 1LL*b *ans.back();
                        int lcm_ = (mul / gcd_);
                        ans.back() = lcm_;
                    }
                    else
                    {
                        ans.push_back(b);
                        break;
                    }
                }
            }
            return ans;
        }
};