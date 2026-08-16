class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n=len(nums)
        mp={}
        for i in range(n):
            if(mp.get(target-nums[i]) is not None):
               return [mp[target-nums[i]],i]
            mp[nums[i]]=i
        return [-1,-1]    
        