class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int>freq(26,0);
        int n=words.size();
        for ( auto& word:words){
             for (auto& ch :word){
                  freq[ch-'a']++;
             }
        }
        for(auto& x : freq){
            if(x%n!=0)
            return 0;
        }
            
      return 1;
    }
};