class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(k==1)
        return "";
        stack<pair<char,int>>st;
        for(char x:s){
              if(st.empty()){
                st.push({x,1});
              } else if(st.top().first==x){
                st.top().second+=1;
                if(st.top().second==k){
                    st.pop();
                }
              }else{
                st.push({x,1});
              }
        }
        string t="";
        while(!st.empty()){
            while(st.top().second--)
            t+=st.top().first;
            st.pop();
        }
        reverse(begin(t),end(t));
        return t;
    }
};