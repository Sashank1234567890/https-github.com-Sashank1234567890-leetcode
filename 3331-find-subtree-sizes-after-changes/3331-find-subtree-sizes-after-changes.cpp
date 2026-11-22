class Solution {
public:
    void dfs(int u,unordered_map<int,vector<int>>& adj,vector<int> mp,vector<int>& par,vector<int>& newPar,string &s) {
        if(mp[s[u]-'a']!=-1)
            newPar[u]=mp[s[u]-'a'];
        else
            newPar[u]=par[u];

        mp[s[u]-'a']=u;

        for(int v:adj[u])
            dfs(v,adj,mp,par,newPar,s);
    }

    void dfs2(int u,unordered_map<int,vector<int>>& adj,vector<int>& size) {
        for(int v:adj[u]) {
            dfs2(v,adj,size);
            size[u]+=size[v];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& par,string s) {
        int n=par.size();
        unordered_map<int,vector<int>> adj;

        for(int i=1;i<n;i++)
            adj[par[i]].push_back(i);

        vector<int> newPar(n);
        vector<int> mp(26,-1);

        dfs(0,adj,mp,par,newPar,s);

        unordered_map<int,vector<int>> adj2;

        for(int i=1;i<n;i++)
            adj2[newPar[i]].push_back(i);

        vector<int> size(n,1);
        dfs2(0,adj2,size);

        return size;
    }
};