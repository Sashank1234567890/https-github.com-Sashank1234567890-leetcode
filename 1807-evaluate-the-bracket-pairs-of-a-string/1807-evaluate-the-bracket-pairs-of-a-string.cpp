class Solution {
public:
    string evaluate(string s, vector<vector<string>>& know) {
        unordered_map<string,string>mp;
        for(auto &k:know){
            mp[k[0]]=k[1];
        }
        int i=0;
        string result="";
        int n=s.size();
        while(i<n){
          if(s[i]=='('){
            i++;
            string key="";
            while(s[i]!=')'){
                key.push_back(s[i]);
                i++;
            }
            if(mp.find(key)!=mp.end()){
                result+=mp[key];
            }else{
                result.push_back('?');
            }
          }else {
            result.push_back(s[i]);
          }
          i++;
        }
         return result;
    }
};