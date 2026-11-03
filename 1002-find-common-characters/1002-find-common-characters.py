class Solution:
    def commonChars(self, words: list[str]) -> list[str]:
        freq = [float('inf')] * 26

        for word in words:
            curr = [0] * 26

            for ch in word:
                curr[ord(ch) - ord('a')] += 1

            for i in range(26):
                freq[i] = min(freq[i], curr[i])

        ans = []

        for i in range(26):
            for j in range(freq[i]):
                ans.append(chr(i + ord('a')))

        return ans