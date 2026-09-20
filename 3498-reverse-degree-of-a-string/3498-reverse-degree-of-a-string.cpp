class Solution {
public:
    int reverseDegree(string s) {
        int val=0;
        int i=1;
        for(char&x:s){
            val+=(i++)*(('z'-x)+1);
        }
        return val;
    }
};