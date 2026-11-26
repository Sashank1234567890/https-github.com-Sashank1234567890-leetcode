class Solution {
public:
    bool canAliceWin(int n) {
        int rem=10;
        bool a=0;
        while(n>0&&rem>0){
           if(rem>n){
            return a;
           }
           n-=rem;
           rem--;
           a=!a;
        }
   return a; }
};