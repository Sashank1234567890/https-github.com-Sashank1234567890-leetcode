class Solution {
public:
    typedef pair<int,int> P;

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> free;

        for(int i=0;i<k;i++){
            free.insert(i);
        }

        priority_queue<P,vector<P>,greater<P>> busy;

        vector<int> freq(k);
        int n=arrival.size();

        for(int i=0;i<n;i++){
            int t=arrival[i];

            while(!busy.empty() && busy.top().first<=t){
                free.insert(busy.top().second);
                busy.pop();
            }

            if(!free.empty()){
                int idx=i%k;
                auto it=free.lower_bound(idx);

                if(it==free.end())
                    it=free.begin();

                int j=*it;

                free.erase(it);
                freq[j]++;

                busy.push({t+load[i],j});
            }
        }

        vector<int> ans;
        int mx=0;

        for(int i=0;i<k;i++){
            if(freq[i]>mx){
                ans={};
                mx=freq[i];
                ans.push_back(i);
            }
            else if(freq[i]==mx){
                ans.push_back(i);
            }
        }

        return ans;
    }
};