class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<int>mp(2,0);
        mp[0]=1;
        bool sum=0;
        int mod=1e9+7;
        int ans=0;
        for(int &x:arr){
            sum=(sum+x)%2;
            ans=(ans+mp[!sum])%mod;
            mp[sum]++;
        }
    return ans;}
};