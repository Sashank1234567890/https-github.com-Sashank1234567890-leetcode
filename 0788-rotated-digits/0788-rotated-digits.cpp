class Solution {
public:
    vector<int> t;

    int solve(int num) {
        if(t[num] != -1)
            return t[num];

        if(num == 0)
            return t[num] = 0;
        
        int remain = solve(num/10);
        if(remain == 2)
            return t[num] = 2;

        int digit_check;
        int d = num%10;

        if (d == 0 || d == 1 || d == 8) 
            digit_check = 0;      
        else if (d == 2 || d == 5 || d == 6 || d == 9) 
            digit_check = 1;       
        else 
            return t[num] = 2;    


        if(remain == 0 && digit_check == 0) {
            return t[num] = 0;
        }

        return t[num] = 1;
        
    }

    int rotatedDigits(int n) {
        int count = 0;
        t.resize(n+1, -1);

        
        for(int i = 1; i <= n; i++) {
            if(solve(i) == 1) {
                count++;
            }
        }

        return count;
    }
};

