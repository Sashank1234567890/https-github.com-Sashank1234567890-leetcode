class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int &x:piles){
            pq.push(x);
        }
        while(k--){
            int x=pq.top();
            pq.pop();
            int f=x/2;
            pq.push(x-f);

        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};