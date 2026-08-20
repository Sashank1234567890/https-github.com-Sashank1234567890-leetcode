class Solution {
public:
    string ans;
    vector<bool> used;

    void solve(string &pattern,string &s,int j,int prepat){
        if(j==pattern.size()+1){
            if(ans=="" || s<ans)
                ans=s;
            return;
        }

        if(prepat==0){
            for(int i=s.back()-'0'+1;i<=9;i++){
                if(!used[i]){
                    used[i]=true;
                    s.push_back(i+'0');

                    solve(pattern,s,j+1,pattern[j]=='D');

                    s.pop_back();
                    used[i]=false;
                }
            }
        }
        else{
            for(int i=s.back()-'0'-1;i>=1;i--){
                if(!used[i]){
                    used[i]=true;
                    s.push_back(i+'0');

                    solve(pattern,s,j+1,pattern[j]=='D');

                    s.pop_back();
                    used[i]=false;
                }
            }
        }
    }

    string smallestNumber(string pattern) {
        string s="";
        ans="";
        used=vector<bool>(10,false);

        for(int i=1;i<=9;i++){
            used[i]=true;
            s.push_back(i+'0');

            solve(pattern,s,1,pattern[0]=='D');

            s.pop_back();
            used[i]=false;
        }

        return ans;
    }
};