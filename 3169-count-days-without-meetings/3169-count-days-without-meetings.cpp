class Solution {
public:
    int countDays(int days, vector<vector<int>>& meet) {
        meet.push_back({days+1,days+1});
        sort(begin(meet),end(meet));

        
       
        int cnt=0;
        int end=1;
        for(auto v:meet){
            int x=v[0];
            int y=v[1];
            if(x>end){
                cnt+=x-end;
                end=y+1;
            }
            else {
                end=max(y+1,end);
            }
        }
        return cnt;
    }
};