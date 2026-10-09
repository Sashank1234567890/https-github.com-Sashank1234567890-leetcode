class Solution {
public:
    
    long long findScore(vector<int>& nums) {
        unordered_map<int,bool>mp;
        int n=nums.size();
        auto comp=[&](int i,int j){
            if(nums[i]==nums[j])
            return i>j;
            return nums[i]>nums[j];
        };
        priority_queue<int,vector<int>,decltype(comp)>pq(comp);
        for(int i=0;i<n;i++){
            pq.push(i);
        }
        long long int ans=0;
        while(!pq.empty()){
            int i=pq.top();
            pq.pop();
            if(!mp[i]){
                if(i>0)
                mp[i-1]=1;
                if(i<n-1)
                mp[i+1]=1;

                mp[i]=1;
                ans+=nums[i];
            }
        }
        return ans;
    }
};