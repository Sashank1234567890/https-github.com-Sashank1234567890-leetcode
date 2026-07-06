class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& time) {
    
        int n=time.size();
        auto comp=[&](auto a,auto b){
            if(a[0]==b[0])
                return b[1]<a[1];
             return a[0]<b[0];   
        };
        sort(begin(time),end(time),comp);
        vector<vector<int>>result;
        result.push_back(time[0]);
        for(int i=1;i<n;i++){
            if(result.back()[1]>=time[i][1]){
                continue;
            }
            result.push_back(time[i]);
        }

       
   return result.size(); }
};