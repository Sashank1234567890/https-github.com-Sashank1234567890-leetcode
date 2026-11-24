class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size(),m=part.size();

        vector<int> lps(m,0);

        int len=0,i=1;

        while(i<m) {
            if(part[i]==part[len]) {
                len++;
                lps[i]=len;
                i++;
            }
            else {
                if(len!=0)
                    len=lps[len-1];
                else
                    i++;
            }
        }

        string ans;
        vector<int> dp;

        int j=0;

        for(char ch:s) {
            while(j>0 && ch!=part[j])
                j=lps[j-1];

            if(ch==part[j])
                j++;

            ans.push_back(ch);
            dp.push_back(j);

            if(j==m) {
                for(int k=0;k<m;k++) {
                    ans.pop_back();
                    dp.pop_back();
                }

                j=dp.empty() ? 0 : dp.back();
            }
        }

        return ans;
    }
};