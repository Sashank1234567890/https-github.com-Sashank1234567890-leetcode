class Solution:
    def commonChars(self, words: list[str]) -> list[str]:
        ans=[]
        st=set()
        for ch in words[0]:
            if ch in st:
                continue
            count=float("inf")
            count=min([word.count(ch) for word in words]) 
            st.add(ch)
            for i in range(count):
                ans.append(ch)
        return ans   
            
        