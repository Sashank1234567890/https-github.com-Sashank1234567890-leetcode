class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq(begin(nums),end(nums));
        int steps=0;
        while(pq.size()>=2 and pq.top()<k){
            long long int x=pq.top(); pq.pop();
             long long int y=pq.top();pq.pop();
            long long  z=min(x,y)*2+max(x,y);
            pq.push(z);
            steps++;
        }
        return steps;
    }
};