class Solution {
public:
    int numberOfMatches(int n) {
       int ans=0;
       while(n>1){
            ans+=n/2;
            n=ceil(1.0*n/2);
       } 
   return ans; }
};