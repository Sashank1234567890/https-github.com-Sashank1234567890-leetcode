class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int dis=0;
            vector<int>fre(3);
            for(int j=i;j<n;j++){
                if(!(fre[s[j]-'a'])){
                     dis++;
                     fre[s[j]-'a']++;
                }
                if(dis==3){
                    cnt+=n-j;
                    break;
                }     
            }
        }
    return cnt;}
};