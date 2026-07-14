class Solution
{  
    public:
    typedef long long LL;
        vector<int> getAverages(vector<int> &nums, int k)
        {
            int n = nums.size();
            vector<LL> pre;
            pre.push_back(0);
            pre[0] = nums[0];
            vector<int> ans;

            for (int x: nums)
            {
                pre.push_back(x + pre.back());
            }
            for (int i = 0; i < n; i++)
            {
                if (i + k >= n || i - k < 0)
                    ans.push_back(-1);
                else
                {
                    LL sum = pre[i + k + 1] - pre[i - k];
                    ans.push_back(sum / (2*k + 1));
                    }
                }

                return ans;
            }
        };