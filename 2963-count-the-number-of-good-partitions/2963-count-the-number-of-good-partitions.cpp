class Solution
{
    public:
      int mod=1e9+7;
      int cnt(vector<int> &nums,unordered_map<int, vector < int>> &mp,int &i){
          int n = nums.size();
                if(i==n)
                return 1;
                int mx=mp[nums[i]][1];
                while(i<=mx){
                    mx=max(mx,mp[nums[i]][1]);
                    i++;
                }
                if(i==n){
                    return 1;
                }

                return 2*(cnt(nums,mp,i))%mod;
      }
        int numberOfGoodPartitions(vector<int> &nums)
        {
            unordered_map<int, vector < int>> mp;
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                if(mp.find(nums[i])==mp.end()){
                    mp[nums[i]]={-1,-1};
                }
                if(mp[nums[i]][0]==-1)
                mp[nums[i]][0]=i;
                mp[nums[i]][1]=i;

            }
            int i=0;
            return cnt(nums,mp,i)%mod;
        }
};