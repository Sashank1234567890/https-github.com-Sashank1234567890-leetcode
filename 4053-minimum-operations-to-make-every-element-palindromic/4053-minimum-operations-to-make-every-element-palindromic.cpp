class Solution {
public:
    vector<long long> generate(long long n) {
        vector<long long> pal;

        for(long long x=1;;x++) {
            string s=to_string(x);
            string rev=s;
            reverse(rev.begin(),rev.end());

            string odd=s+rev.substr(1);
            long long p=stoll(odd);

            if(p>n)
                break;

            pal.push_back(p);

            string even=s+rev;
            p=stoll(even);

            if(p<=n)
                pal.push_back(p);
        }

        sort(pal.begin(),pal.end());
        return pal;
    }

    long long minOperations(vector<int>& nums) {

        static vector<long long> pal=generate(2000000000LL);

        static vector<long long> even,odd;

        if(even.empty()) {
            for(long long x:pal) {
                if(x%2==0)
                    even.push_back(x);
                else
                    odd.push_back(x);
            }
        }

        long long ans=0;

        for(long long x:nums) {
            vector<long long>& v=(x%2==0)?even:odd;

            int pos=lower_bound(v.begin(),v.end(),x)-v.begin();

            long long cost=LLONG_MAX;

            if(pos<v.size())
                cost=min(cost,(v[pos]-x)/2);

            if(pos>0)
                cost=min(cost,(x-v[pos-1])/2);

            ans+=cost;
        }

        return ans;
    }
};