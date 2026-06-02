class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for idx_i, i in enumerate(nums):
            if (target-i) in nums[idx_i+1:]:
                return [idx_i, nums[idx_i+1:].index(target-i)+idx_i+1]
        return [0,0]
        