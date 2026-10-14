class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*9<sum){
            return "";
        }
        string ans="";
        while(num--){
              if(sum>9){
                 ans.push_back('9');
                 sum-=9;
              }else{
                ans.push_back(sum+'0');
                sum=0;
              }
        }
    return ans;}
};