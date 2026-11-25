class Solution {
public:
    string countAndSay(int n) {
        string s="1";

        for(int k=2;k<=n;k++) {
            string ans="";
            int i=0;
            int l=s.length();

            while(i<l) {
                char x=s[i];
                int cnt=0;

                while(i<l&&s[i]==x) {
                    cnt++;
                    i++;
                }

                ans+=to_string(cnt);
                ans.push_back(x);
            }

            s=ans;
        }

        return s;
    }
};