class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        freq=Counter(nums)
        mx=max(freq.values())
        return sum(map(lambda x:x[1] if x[1]==mx else 0,freq.items()))