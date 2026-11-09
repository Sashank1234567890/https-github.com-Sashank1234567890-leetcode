class Solution {
public:
    typedef pair<int,int> P;
    vector<int> bit;

    void update(int i,int val,int n){
        while(i<=n){
            bit[i]+=val;
            i+=i&-i;
        }
    }

    int query(int i){
        int ans=0;

        while(i>0){
            ans+=bit[i];
            i-=i&-i;
        }

        return ans;
    }

    int kth(int k,int n){
        int idx=0;

        for(int i=17;i>=0;i--){
            int next=idx+(1<<i);

            if(next<=n && bit[next]<k){
                idx=next;
                k-=bit[next];
            }
        }

        return idx+1;
    }

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n=arrival.size();

        bit.resize(k+1);

        for(int i=1;i<=k;i++){
            update(i,1,k);
        }

        priority_queue<P,vector<P>,greater<P>> pq;

        vector<int> freq(k,0);

        for(int i=0;i<n;i++){
            int t=arrival[i];

            while(!pq.empty() && pq.top().first<=t){
                int j=pq.top().second;
                pq.pop();

                update(j+1,1,k);
            }

            int idx=i%k;
            int cnt=query(k)-query(idx);

            if(cnt==0){
                cnt=query(k);
                if(cnt==0)
                    continue;

                int j=kth(1,k)-1;

                update(j+1,-1,k);
                freq[j]++;
                pq.push({t+load[i],j});
            }
            else{
                int before=query(idx);
                int j=kth(before+1,k)-1;

                update(j+1,-1,k);
                freq[j]++;
                pq.push({t+load[i],j});
            }
        }

        vector<int> ans;
        int mx=*max_element(freq.begin(),freq.end());

        for(int i=0;i<k;i++){
            if(freq[i]==mx)
                ans.push_back(i);
        }

        return ans;
    }
};