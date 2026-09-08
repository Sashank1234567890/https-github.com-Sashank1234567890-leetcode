class Solution {
public:
    int countCommas(int n) {
        if(n<=999)
        return 0;
        int k=0;
        int d=n;
        while(d>999){
              k++;
              d/=1000;
        }
        int ans=0;
        while(n>999){
            int limit=pow(1000,k);
            ans+=(n-limit+1)*k;
            n/=1000;k--;
        }
    return ans;}
};