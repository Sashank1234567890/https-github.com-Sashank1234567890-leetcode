class Solution {
public:
    bool checkString(string s) {
        bool start=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                if(start)
                return 0; 
                continue;
            }else{
                start=1;
            }
        }
   return 1; }
};