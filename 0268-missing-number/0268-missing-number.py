class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        # 0 ~ n 을 돌면서
        for i in range(len(nums)+1):
            # nums에 없으면 return
            if i not in nums:
                return i