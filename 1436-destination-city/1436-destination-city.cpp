class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> st;

        for(auto &path:paths){
            st.insert(path[1]);
        }

        for(auto &path:paths){
            st.erase(path[0]);
        }

        return *st.begin();
    }
};