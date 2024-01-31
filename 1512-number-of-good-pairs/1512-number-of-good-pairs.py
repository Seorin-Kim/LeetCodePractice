class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        ans = 0

        # i,j 차례대로 for문 돌면서,
        for i in range(len(nums)):
            for j in range(len(nums)):
                # 조건에 맞으면 ans++
                if i < j and nums[i] == nums[j]:
                    ans += 1
        
        return ans