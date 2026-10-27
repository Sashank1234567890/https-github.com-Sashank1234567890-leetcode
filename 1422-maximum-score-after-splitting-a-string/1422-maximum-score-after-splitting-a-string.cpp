class Solution {
public:
    int maxScore(string s) {
        int cones=count(begin(s),end(s),'1');
        int ans=0;
        int czero=0;
        int n=s.size();
        for(int i=0;i<n-1;i++){
           char x=s[i];
            if(x=='0'){
                czero++;
            }else{
                cones--;
            }
             ans=max(ans,czero+cones);
        }
        return ans;
    }
};