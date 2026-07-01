class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        auto check=[&](long long  t){
           long long  trips=0;
            for(long long  x:time){
                trips+=t/x;
                if(trips>=totalTrips){
                    return true;
                }
            }
            return false;
        };
        long long l=1;
        long long r = 1LL * totalTrips * (*min_element(time.begin(), time.end()));
        while(l<r){
            long long  mid=l+(r-l)/2;
            if(check(mid)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        
    return r;}
};