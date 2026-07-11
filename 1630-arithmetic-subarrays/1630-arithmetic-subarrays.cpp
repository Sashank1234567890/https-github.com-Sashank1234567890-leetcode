class Solution
{
    public:
        vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector< int > &r)
        {
            vector<bool> result;

            for (int i = 0; i < l.size(); i++)
            {
                int start = l[i], end = r[i];
                int mn = INT_MAX, mx = INT_MIN;

                for (int j = start; j <= end; j++)
                {
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);
                }

                int len = end - start + 1;

                if ((mx - mn) % (len - 1) != 0)
                {
                    result.push_back(false);
                    continue;
                }

                int diff = (mx - mn) / (len - 1);

                unordered_set<int> s;

                for (int j = start; j <= end; j++)
                {
                    s.insert(nums[j]);
                }

                bool ok = true;
                for (int j = 0; j < len; j++)
                {
                    int expected = mn + j * diff;
                    if (s.find(expected) == s.end())
                    {
                        ok = false;
                        break;
                    }
                }

                result.push_back(ok);
            }

            return result;
        }
};