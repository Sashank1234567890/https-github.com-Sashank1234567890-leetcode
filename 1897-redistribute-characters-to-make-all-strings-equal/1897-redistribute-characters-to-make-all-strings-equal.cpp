class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int count[26] = {0};
        
        for (string &word : words) {
            for (char &ch : word) {
                ++count[ch - 'a'];
            }
        }
        
        auto lambda = [&](int c) {
                   return c % n == 0;
        };
        
        return all_of(begin(count), end(count), lambda);
        

        
    }
};