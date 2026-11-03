class Solution:
    def relativeSortArray(self, arr1: list[int], arr2: list[int]) -> list[int]:
        mp={}
        for i,x in enumerate(arr2):
            mp[x]=i
        print(mp)   
        #mp.get(x,1001) mean if x not exist return 1001
        arr1.sort(key=lambda x: (mp.get(x,1001),x)) 
        return arr1;    

        