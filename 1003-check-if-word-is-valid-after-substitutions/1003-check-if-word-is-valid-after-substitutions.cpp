class Solution {
public:
    bool isValid(string s) {
        int i=0,j=0;
        while(j<s.size()){
            s[i++]=s[j++];
            if(i>=3&&s[i-1]=='c'&&s[i-2]=='b'&&s[i-3]=='a')
            i-=3;
        }
        s.resize(i);
        return s=="";
    }
};