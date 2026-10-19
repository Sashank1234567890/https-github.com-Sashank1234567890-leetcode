class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
      int l=0,m=0,h=nums.size()-1;
      while(m<=h){
        if(nums[m]<target){
            swap(nums[l++],nums[m++]);
        }else if(nums[m]>target){
            swap(nums[m],nums[h--]);
        }else{
            m++;
        }
      }
    //   cout<<l<<" "<<h;
      if(l>h)
      return {};
      vector<int>ans;
        for(int i=l;i<=h;i++){
        ans.push_back(i);
      }
      return ans;
    }
};
