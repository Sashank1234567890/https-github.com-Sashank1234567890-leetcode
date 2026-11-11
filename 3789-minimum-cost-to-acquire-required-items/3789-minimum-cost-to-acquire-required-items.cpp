class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long cost=0;
        int mn=min(need1,need2);
        cost+=min(1LL*cost1*mn+1LL*cost2*mn,1LL*costBoth*mn);
        need1-=mn;
        need2-=mn;
        if(need1){
            cost+=min(1LL*cost1*need1,1LL*costBoth*need1);
        }
        if(need2){
            cost+=min(1LL*cost2*need2,1LL*costBoth*need2);
        }
        return cost;
        
    }
};