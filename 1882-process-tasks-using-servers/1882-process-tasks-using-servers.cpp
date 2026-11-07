class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> free;
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> busy;

        int n=servers.size();
        int m=tasks.size();

        for(int i=0;i<n;i++){
            free.push({servers[i],i});
        }

        vector<int> ans(m);

        long long t=0;

        for(int i=0;i<m;i++){
            t=max(t,(long long)i);

            while(!busy.empty() && busy.top()[0]<=t){
                free.push({busy.top()[1],busy.top()[2]});
                busy.pop();
            }

            if(free.empty()){
                t=busy.top()[0];

                while(!busy.empty() && busy.top()[0]<=t){
                    free.push({busy.top()[1],busy.top()[2]});
                    busy.pop();
                }
            }

            auto p=free.top();
            free.pop();

            ans[i]=p.second;

            busy.push({t+tasks[i],p.first,p.second});
        }

        return ans;
    }
};