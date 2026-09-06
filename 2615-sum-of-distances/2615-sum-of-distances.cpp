class Solution
{
public:
    typedef long long LL;

    vector<long long> distance(vector<int>& nums)
    {
        int n = nums.size();
        vector<LL> ans(n);

        unordered_map<LL, pair<LL, LL>> mp;

        
        for(int i = 0; i < n; i++)
        {
            auto &[cnt, sum] = mp[nums[i]];

            ans[i] += (LL)cnt * i - sum;

            cnt++;
            sum += i;
        }

        mp.clear();

     
        for(int i = n - 1; i >= 0; i--)
        {
            auto &[cnt, sum] = mp[nums[i]];

            ans[i] += sum - (LL)cnt * i;

            cnt++;
            sum += i;
        }

        return ans;
    }
};