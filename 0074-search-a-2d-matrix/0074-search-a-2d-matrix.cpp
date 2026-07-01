class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {

        int m = mat.size();
        int n = mat[0].size();

        int left = 0;
        int right = m - 1;

        while(left <= right){

            int mid = left + (right-left)/2;
            int i=0;
            int j=n-1;
            
            if((mat[mid][0]<=target)&&(mat[mid][n-1]>=target)){
                while(i<=j){
                    int midj=i+(j-i)/2;
                    if(mat[mid][midj]==target){
                        return true;
                    }
                    else if(mat[mid][midj]<target){
                        i=midj+1;
                    }
                    else{
                        j=midj-1;
                    }
                }
                return false;
            }

            else if(mat[mid][n-1] < target)
                left = mid + 1;

            else if(mat[mid][0]>target)
                right = mid - 1;
        }

        return false;
    }
};