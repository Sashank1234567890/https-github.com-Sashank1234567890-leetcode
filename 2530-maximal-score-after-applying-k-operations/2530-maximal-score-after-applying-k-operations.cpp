class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq(begin(nums),end(nums));
        long long int profit=0;
        while(k-- &&!pq.empty()){
            int x=pq.top();
            pq.pop();
            profit+=x;
            x=(x+2)/3;
            pq.push(x);
        }
        return profit;
    }
};