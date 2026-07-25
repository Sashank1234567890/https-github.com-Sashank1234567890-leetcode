class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
    int  cnt=0;
    int prev=-1; 
    for(int i=0;i<bank.size();i++){
        int one=0;
        for(int j=0;j<bank[i].size();j++){
          one+=(bank[i][j]=='1');
        }
        // cout<<one<<endl;
        if(prev==-1){
          prev=one;
          continue;
        }
        if(one==0)
          continue;
        cnt+=(one*prev);
        prev=one;
    }

      return cnt;  
    }
};