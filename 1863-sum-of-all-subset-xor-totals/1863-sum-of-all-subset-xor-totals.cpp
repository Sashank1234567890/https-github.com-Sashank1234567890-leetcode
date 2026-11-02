class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int total=1<<n;
        int sum=0;
        for(int i=0;i<total;i++){
            int Xor=0;
            for(int j=0;j<32;j++){
                   if((1<<j)&i){
                    Xor^=nums[j];
                   }
            }
            sum+=Xor;
        }
   return sum; }
};