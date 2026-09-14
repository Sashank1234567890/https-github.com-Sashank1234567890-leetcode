class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        bool pali=0;
        int n=words.size();

        for(int i=0;i<n;i++){
            string s=words[i];
            mp[s]++;
        }

        int cnt=0;

        for(auto &[s,freq]:mp){

            if(freq==0)
                continue;

            string r;
            r+=s[1];
            r+=s[0];

            if(r==s){
                cnt+=mp[s]/2;

                if(mp[s]%2)
                    pali=1;
            }
            else{
                if(mp.find(r)!=mp.end())
                cnt+=min(mp[r],mp[s]);
            }
            mp[s]=0;
        }

        return (cnt*4+pali*2);
    }
};