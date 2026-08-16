class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n=len(nums)
        mp={}
        for i in range(n):
            if target-nums[i] in mp:
               return [mp[target-nums[i]],i]
            mp[nums[i]]=i
        return [-1,-1]    
        