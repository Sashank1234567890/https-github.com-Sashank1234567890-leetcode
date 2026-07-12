class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1)
            return 1;
        
        int totalSum = n * (n+1)/2;
        
        int pivot = sqrt(totalSum);
        
        if(pivot*pivot == totalSum)
            return pivot;
        
        return -1;
        
    }
};