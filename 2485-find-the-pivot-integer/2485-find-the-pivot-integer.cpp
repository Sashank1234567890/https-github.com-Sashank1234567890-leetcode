class Solution {
public:
    int getsum(int n){
        return n*(n+1)/2;
    }
    int pivotInteger(int n) {
        int sum=getsum(n);
        int l=1;
        int r=n;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int x=getsum(mid);
            if(x==sum-(x-mid))
              return mid;
            else if(x<sum-(x-mid))
               l=mid+1;
            else
               r=mid-1;
        }
   return ans; }
};