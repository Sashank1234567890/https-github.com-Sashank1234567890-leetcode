class Solution:
    def commonChars(self, words: list[str]) -> list[str]:
        ans = Counter(words[0])

        for word in words[1:]:
            ans &= Counter(word)#minimum freq

        return list(ans.elements())