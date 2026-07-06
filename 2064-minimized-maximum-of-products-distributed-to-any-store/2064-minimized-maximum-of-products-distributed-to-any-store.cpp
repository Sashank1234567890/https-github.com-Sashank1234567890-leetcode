class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int l=1;
        int r=*max_element(begin(q),end(q));
        int result=0;
        auto check=[&](int x){
          int cnt=n;

          for(float val:q){
            cnt-=ceil(val/x);
            if(cnt<0)
              return false;
          }
          return true;
        };
        while(l<=r){
           int mid=l+(r-l)/2;
           if(check(mid)){
            result=mid;
            r=mid-1;
           }
           else{
            l=mid+1;
           }
        }
    return result;}
};