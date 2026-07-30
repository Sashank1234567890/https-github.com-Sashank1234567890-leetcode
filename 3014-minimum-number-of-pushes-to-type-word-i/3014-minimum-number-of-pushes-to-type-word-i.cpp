class Solution {
public:
    int minimumPushes(string word) {
     unordered_map<int,int>mp;
        int cost=0;
        int i=2;
        for(char x:word){
            if(i>9)
              i=2;
            mp[i]++;
            cost+=mp[i];
            i++;
        }
            
   return cost; }
};