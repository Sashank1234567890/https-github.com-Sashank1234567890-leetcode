class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<pair<int,int>>mp(26,{301,-1});
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]-'a']={min(i,mp[s[i]-'a'].first),max(i,mp[s[i]-'a'].second)};
        }
        int ans=-1;
        for (auto &[i,j]:mp){
            if(i!=INT_MAX){
                ans=max(ans,j-i-1);
            }
        }
   return ans; }
};