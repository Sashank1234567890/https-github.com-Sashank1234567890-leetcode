class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%3)
        return {};
        sort(begin(nums),end(nums));
        vector<vector<int>>ans;
        for(int i=0;i<=n-3;i+=3){
            if(nums[i+2]-nums[i]>k)
            return {};
            ans.push_back(vector<int>(nums.begin()+i,nums.begin()+i+3));
        }
   return ans; }
};