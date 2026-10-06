class Solution {
public:
    int M=1e9+7;

    typedef pair<int,int> P;

    long long getSum(vector<int>& nums,int n,int k) {

        priority_queue<int> pq;
        long long sum=0;

        for(int i=0;i<n;i++) {

            int cur=0;

            for(int j=i;j<n;j++) {

                cur+=nums[j];

                pq.push(cur);
                sum+=cur;

                if(pq.size()>k) {
                    sum-=pq.top();
                    pq.pop();
                }
            }
        }

        return sum;
    }

    int rangeSum(vector<int>& nums,int n,int left,int right) {

        long long r=getSum(nums,n,right);
        long long l=getSum(nums,n,left-1);

        return (r-l+M)%M;
    }
};