class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
       unordered_map<int,int>mp;
       int cnt=0;
       for(int &x:nums){
        cnt+=mp[x];
        mp[x]++;
       } 
    return cnt;}
};