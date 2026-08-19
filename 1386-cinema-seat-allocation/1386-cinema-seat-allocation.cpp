class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        unordered_map<int,unordered_set<int>> mp;

        for(auto v:rs){
            int i=v[0];
            int j=v[1];

            if(j>=2 && j<=5 && !mp[i].count(1))
                mp[i].insert(1);

            if(j>=4 && j<=7 && !mp[i].count(2))
                mp[i].insert(2);

            if(j>=6 && j<=9 && !mp[i].count(3))
                mp[i].insert(3);
        }

        int ans=(n-mp.size())*2;

        for(auto [i,st]:mp){
            if(!st.count(1) && !st.count(3))
                ans+=2;
            else if(!st.count(1) || !st.count(2) || !st.count(3))
                ans++;
        }

        return ans;
    }
};