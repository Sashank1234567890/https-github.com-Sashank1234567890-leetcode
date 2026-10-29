class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mp1 = {}
        mp2 = {}

        for x, y in zip(s, t):
            if x in mp1 and mp1[x] != y:
                return False
            if y in mp2 and mp2[y] != x:
                return False

            mp1[x] = y
            mp2[y] = x

        return True