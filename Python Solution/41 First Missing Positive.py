# Link: https://leetcode.com/problems/first-missing-positive/

class Solution:
    def firstMissingPositive(self, nums) -> int:
        n = len(nums)
        for i in range(n):
            while 0 < nums[i] <= n and nums[i] != i + 1:
                index = nums[i] - 1
                nums[index], nums[i] = nums[i], nums[index]
                if nums[index] == nums[i]:
                    break
        
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        return n + 1



obj = Solution()
print(obj.firstMissingPositive([1,2,0]))
