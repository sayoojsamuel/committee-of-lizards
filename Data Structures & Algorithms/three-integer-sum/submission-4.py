class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[List[int]]:
        # sorted nums
        solutions = []
        for idj, j in enumerate(nums): 
            for idk, k in enumerate(nums[idj+1:]):
                if (k+j) == target:
                    solutions.append([j,k])
        return solutions

    def efficientTwoSum(self, nums: List[int], target: int) -> List[List[int]]:
        # sorted nums
        solutions = []
        idj = 0
        idk = len(nums) - 1
        while (idj < idk): 
            twoSum = nums[idj] + nums[idk]
            if twoSum == target:
                solutions.append([nums[idj],nums[idk]])
                idj += 1
                idk -= 1
            elif twoSum < target:
                idj += 1
            elif twoSum > target:
                idk -= 1
        return solutions

    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        # -i = (j + k)
        solutions = []
        for idx, i in enumerate(nums):
            sub_solutions = self.efficientTwoSum(nums[idx+1:], -i)
            if not sub_solutions: 
                continue
            for solution in sub_solutions:
                solutions.append([i] + solution)
        unique_solutions = [list(x) for x in set(tuple(x) for x in solutions)]
        return unique_solutions


