class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mp = {}
        used = set()

        for x, y in zip(s, t):
            if x in mp:
                if mp[x] != y:
                    return False
            else:
                if y in used:
                    return False
                mp[x] = y
                used.add(y)

        return True