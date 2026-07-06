class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>st;
        while(1){
            if(n==1)
             return true;
            if(st.find(n)!=st.end()){
                return false;
            }
            st.insert(n);
            long long sum=0;
            while(n){
                int d=n%10;
                sum+=d*d;
                n/=10;
            } 
             n=sum;
        }
   return false; }
};