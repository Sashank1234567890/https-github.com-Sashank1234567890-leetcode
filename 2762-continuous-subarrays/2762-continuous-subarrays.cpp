class Solution {
public:
    #define P pair<int, int>

    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        priority_queue<P, vector<P>, greater<P>> minHeap;
        priority_queue<P> maxHeap;


        int i = 0;
        int j = 0;
        long long count = 0;

        while(j < n) { 
            minHeap.push({nums[j], j}); 
            maxHeap.push({nums[j], j}); 

            while(abs(maxHeap.top().first - minHeap.top().first) > 2) {
                i++;

                while(!maxHeap.empty() && maxHeap.top().second < i) {
                    maxHeap.pop();
                }

                while(!minHeap.empty() && minHeap.top().second < i) {
                    minHeap.pop();
                }
            }

            count += j-i+1;
            j++;
        }
     
        return count;
    }
};

