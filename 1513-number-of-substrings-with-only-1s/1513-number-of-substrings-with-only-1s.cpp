class Solution {
public:
    int numSub(string s) {
       long long int ans=0;
       int MOD=1e9+7;
        int i=0,j=0;
        while(s[i]=='0'){
            i++;
        }
        int n=s.size();
        if(i==n)
        return 0;
        j=i;
        
        while(j<n){
            if(s[j]=='0'){
                while(j<n&&s[j]=='0')
                j++;
                i=j;
            }
            if(j!=n)
            ans=(ans+(j-i)+1)%MOD;
            j++;
        }
    return ans;}
};