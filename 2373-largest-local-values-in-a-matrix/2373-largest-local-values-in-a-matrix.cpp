class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        int k=3;
        int m=n-k+1;

        vector<vector<int>>temp(n,vector<int>(m));

        // Step 1: Horizontal sliding window maximum
        for(int i=0;i<n;i++){
            deque<int>q;

            for(int j=0;j<n;j++){
                while(!q.empty() && q.front()<=j-k)
                    q.pop_front();

                while(!q.empty() && grid[i][q.back()]<=grid[i][j])
                    q.pop_back();

                q.push_back(j);

                if(j>=k-1)
                    temp[i][j-k+1]=grid[i][q.front()];
            }
        }

        vector<vector<int>>ans(m,vector<int>(m));

        // Step 2: Vertical sliding window maximum
        for(int j=0;j<m;j++){
            deque<int>q;

            for(int i=0;i<n;i++){
                while(!q.empty() && q.front()<=i-k)
                    q.pop_front();

                while(!q.empty() && temp[q.back()][j]<=temp[i][j])
                    q.pop_back();

                q.push_back(i);

                if(i>=k-1)
                    ans[i-k+1][j]=temp[q.front()][j];
            }
        }

        return ans;
    }
};