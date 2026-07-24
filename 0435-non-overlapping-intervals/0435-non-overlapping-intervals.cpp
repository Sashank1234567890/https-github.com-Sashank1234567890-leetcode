class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& interval) {
        ranges::sort(interval);
        int start=interval[0][0];
        int end=interval[0][1];
        int n=interval.size();
        int cnt=0;
        for(int i=1;i<n;i++){
            if(interval[i][0]<end){
              cnt++;
              end=min(interval[i][1],end);
            }
            else{
                end=interval[i][1];
            }
        }

    return cnt;}
};