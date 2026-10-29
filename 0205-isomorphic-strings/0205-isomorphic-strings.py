class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mp1={}
        mp2={}
        for x,y in zip(s,t):
            if x in mp1:
                if y!=mp1[x]:
                    return False
            else:
                mp1[x]=y        
            if y in mp2:
                if x !=mp2[y]:
                    return False
            else:
                mp2[y]=x        

        return True;    
