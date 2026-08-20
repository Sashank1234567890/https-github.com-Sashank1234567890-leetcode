class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();

        vector<vector<int>> pos(26);

        for(int i=0;i<n;i++)
            pos[s[i]-'a'].push_back(i);

        vector<bool> removed(n,false);

        for(int i=0;i<n;i++){
            if(removed[i])
                continue;

            int c=s[i]-'a';

            int p=lower_bound(pos[c].begin(),pos[c].end(),i)-pos[c].begin();

            int l=p-1;
            int r=p+1;

            while(l>=0 && removed[pos[c][l]])
                l--;

            while(r<pos[c].size() && removed[pos[c][r]])
                r++;

            if(l>=0 && r<pos[c].size()){
                removed[pos[c][l]]=true;
                removed[pos[c][r]]=true;
            }
        }

        int ans=0;

        for(int i=0;i<n;i++){
            if(!removed[i])
                ans++;
        }

        return ans;
    }
};