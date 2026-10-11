class Solution {
public:
    int removeDuplicates(vector<int>& s) {
        int i=0,j=1;
        int n=s.size();
        while(j<n){
             if(s[j]!=s[i]){
               s[++i]=s[j];
             }
             j++;
        }
   return i+1; }
};