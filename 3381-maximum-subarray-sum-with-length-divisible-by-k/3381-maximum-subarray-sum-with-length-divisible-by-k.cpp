class Solution
{
public:
    long long maxSubarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, long long> mp;

        long long pre = 0;
        long long ans = LLONG_MIN;

        mp[0] = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            pre += nums[i];

            int rem = (i + 1) % k;

            if(mp.contains(rem))
            {
                ans = max(ans, pre - mp[rem]);
                mp[rem] = min(mp[rem], pre);
            }
            else
                mp[rem] = pre;
        }

        return ans;
    }
};