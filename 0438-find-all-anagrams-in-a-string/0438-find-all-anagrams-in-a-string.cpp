class Solution {
public:
    vector<int> findAnagrams(string txt, string pat) {
           vector<int>freq(26,0);
        for(char x:pat){
            freq[x-'a']++;
        }
        int n=txt.size();
        int k=pat.size();
        vector<int>ans;
        auto check=[&](vector<int>a){
            for(int i=0;i<a.size();i++){
                if(a[i])
                return 0;
            }
            return 1;
        };
        for(int i=0;i<n;i++){
            freq[txt[i]-'a']--;
            if(i>=k){
                freq[txt[i-k]-'a']++;
            }
            if(check(freq))
               ans.push_back(i-k+1);
        }
    return ans;}
};