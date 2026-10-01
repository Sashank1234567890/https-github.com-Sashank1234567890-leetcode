class Solution {
public:
    int maxDepth(string s) {
        int open=0;
        int mx=0;
        int i=0,n=s.size();
        while(i<n){
            if(s[i]=='('){
                open++;
                 mx=max(open,mx);
            }else if(s[i]==')'){     
                open--;
            }
            i++;
        }
   return mx; }
};