class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        vector<int>ans(j+1,0);
        int k=j;
        while(i<=j){
            long long val1=nums[i]*nums[i];
            long long val2=nums[j]*nums[j];

            if(val1>=val2){
                ans[k--]=val1;
                i++;
            }else{
                ans[k--]=val2;
                j--;
            }
        }
    return ans;}
};