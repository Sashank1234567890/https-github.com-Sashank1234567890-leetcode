class Solution {
public:
    int upper_bound(vector<int>&nums,int &tar){
        int l=0;
        int h=nums.size()-1;
        int idx=h+1;
        while(l<=h){
            int mid=(l+h)/2;
         if(nums[mid]==tar){
            idx=mid;
            l=mid+1;
         }else if(nums[mid]>tar){
            h=mid-1;
         }
         else{
            l=mid+1;
         }
        }
        return idx;
    }
    int lower_bound(vector<int>&nums,int &tar){
        int l=0;
        int h=nums.size()-1;
        int idx=h+1;
        while(l<=h){
            int mid=(l+h)/2;
         if(nums[mid]==tar){
            idx=mid;
            h=mid-1;
         }else if(nums[mid]<tar){
            l=mid+1;
         }else{
            h=mid-1;
         }
        }
        return idx;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        ranges::sort(nums);
        vector<int>ans;
        int r=upper_bound(nums,target);
        int l=lower_bound(nums,target);
               cout<<l<<" "<<r;
        if(l==nums.size()){
            return {};
        }
 
        for(int i=l;i<=r;i++){
            ans.push_back(i);
        }
        return ans;
    }
};