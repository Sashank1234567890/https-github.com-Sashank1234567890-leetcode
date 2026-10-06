class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>>arr;
        int n=profits.size();
        for(int i=0;i<n;i++){
            arr.push_back({capital[i],profits[i]});
        }
        sort(arr.begin(),arr.end());
        priority_queue<int>pq;
        int i=0;
        while(k--){
             while(i<n&&arr[i][0]<=w){
               pq.push(arr[i][1]);
               i++;
             }
             if(pq.empty())
             break;
             w+=pq.top();pq.pop();
             

        }
        return w;
    }
};