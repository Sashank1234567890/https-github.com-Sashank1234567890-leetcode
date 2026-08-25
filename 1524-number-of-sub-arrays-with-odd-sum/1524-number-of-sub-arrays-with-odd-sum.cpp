class Solution
{
    public:
        int numOfSubarrays(vector<int> &arr)
        {
            vector<int>mp(2,0);
            mp[0] = 1;
            int mod=1e9+7;
            int ans = 0;
            int sum=0;
            for (int x: arr)
            {   sum+=x;
                bool p = sum % 2;
                ans = (ans+mp[!p])%mod;
                mp[p]++;
            }
            return ans;
        }
};