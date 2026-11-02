class Solution {
public:
    int countStudents(vector<int>& stu, vector<int>& san) {
        int n=san.size();
        queue<int>q;
        int j=0;

        for(int i=0;i<n;i++){
            if(san[j]!=stu[i]){
                q.push(i);
                continue;
            }
            j++;
        }

        int cnt=0;

        while(j<n&&!q.empty()&&cnt<q.size()){
            int idx=q.front();
            q.pop();

            if(san[j]!=stu[idx]){
                q.push(idx);
                cnt++;
                continue;
            }
            else{
                cnt=0;
                j++;
            }
        }

        return q.size();
    }
};