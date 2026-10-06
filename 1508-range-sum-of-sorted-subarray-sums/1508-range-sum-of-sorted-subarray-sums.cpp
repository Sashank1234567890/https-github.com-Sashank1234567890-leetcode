class Solution {
public:
    typedef pair<int,int> P;

    long long getSum(vector<int>& nums,int n,int k) {

        priority_queue<P,vector<P>,greater<P>> pq;

        for(int i=0;i<n;i++)
            pq.push({nums[i],i});//think as n sorted sequence

        long long sum=0;

        for(int cnt=0;cnt<k;cnt++) {

            auto [val,i]=pq.top();
            pq.pop();

            sum+=val;

            if(i+1<n)
                pq.push({val+nums[i+1],i+1});
        }

        return sum;
    }

    int rangeSum(vector<int>& nums,int n,int left,int right) {

        long long r=getSum(nums,n,right);
        long long l=getSum(nums,n,left-1);

        return (r-l)%1000000007;
    }
};