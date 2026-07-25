class Solution {
public:
    #define ll long long

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    long long beautifulSubstrings(string s, int k) {
        ll vowel = 0;
        ll consonant = 0;

        ll result = 0;

        unordered_map<ll, unordered_map<ll, ll>> mp; //key = (v-c) , value = map (vowel ka count past me -> count)
        mp[0][0] = 1;

        for(char &ch : s) {

            if(isVowel(ch)) {
                vowel++;
            } else {
                consonant++;
            }

            ll pSum = (vowel - consonant);

            for(auto &[pastVowelCount, count] : mp[pSum]) {
                
               
                if((vowel%k - pastVowelCount) * (vowel%k - pastVowelCount) % k == 0) {
                    result += count;
                }

            }

            mp[pSum][vowel%k]++;
        }

        return result;
    }
};