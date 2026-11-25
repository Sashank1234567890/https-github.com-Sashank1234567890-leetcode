class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
           return "1";
        string ans="";
        string s=countAndSay(n-1);
        int l=s.length();
        int i=0;
        while(i<l){
            char x=s[i];
            i++;
            int cnt=1;
     
            while(i<l&&s[i]==x){
                cnt++;
                i++;
            }
            string scnt=to_string(cnt);
            ans+=scnt;
            ans.push_back(x);
        }   

        return ans;
    }
};