class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n)
        return 1;
        int ans=0;
        int i=0;
        while(n){
            bool bit=!(n&1);
            n>>=1;
            ans|=(bit)<<i;
            i++;
        }
        return ans;
    }
};