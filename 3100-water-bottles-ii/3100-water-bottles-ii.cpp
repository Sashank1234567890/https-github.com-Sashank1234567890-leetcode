class Solution {
public:
    int maxBottlesDrunk(int val,int cost) {
        int cnt=0,empty=0;
        while(val){
              cnt+=val;
             empty+=val;
              val=0;
              while(empty>=cost){
                val++;
                empty-=cost;
                cost++;
              }
        }
   return cnt; }
};