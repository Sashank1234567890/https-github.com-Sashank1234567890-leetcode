class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one=0;
        int n=s.size();
        for(char &ch:s){
            if(ch=='1')
            one++;
        }
        if(one==1)
        return  string(n-1,'0')+"1";
        string ans="";
        for(int i=0;i<one-1;i++){
            ans.push_back('1');
        }
         for(int i=0;i<n-one;i++){
            ans.push_back('0');
        }
        ans.push_back('1');
        return ans;;
    }
};