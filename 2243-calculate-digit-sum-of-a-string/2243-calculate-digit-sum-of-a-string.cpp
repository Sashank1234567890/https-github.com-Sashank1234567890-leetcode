class Solution {
public:
    string digitSum(string s, int k) {
        int sum=0;
        string ans="";

        while(s.size()>k){
            ans="";
            int n=s.size();

            for(int i=0;i<n;i++){
                sum+=s[i]-'0';

                if(i==n-1||(i+1)%k==0){
                    ans+=to_string(sum);
                    sum=0;
                }
            }

            s=ans;
        }

        return s;
    }
};