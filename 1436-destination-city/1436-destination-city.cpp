class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,bool>mp;
        unordered_set<string>st;
        for(auto &path:paths){
            string u=path[0];
            string v=path[1];
            if(mp.find(v)==mp.end()){
               st.insert(v);
            }
            if(st.count(u)){
                st.erase(u);
            }
            mp[u]=1;
        }
        
        return *st.begin();
    }
};