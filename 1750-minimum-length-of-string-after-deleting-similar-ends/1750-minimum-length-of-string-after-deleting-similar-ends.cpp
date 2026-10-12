class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
          if(s[i]==s[j]){
            char x=s[i];
            while(i<j&&s[i]==x){
                i++;
            }
             while(i<=j&&s[j]==x){
                j--;
            }
          }else{
            break;
          }
        }
        return j-i+1;
    }
};