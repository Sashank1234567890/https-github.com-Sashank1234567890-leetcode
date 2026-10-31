class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one=0;
        int n=s.size();
        for(char ch:s){
            if(ch=='1')
            one++;
        }
        if(one==1)
        return  string(n-1,'0')+"1";

        return string(one-1,'1')+string(n-one,'0')+"1";
    }
};