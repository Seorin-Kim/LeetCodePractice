class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        ans = []

        # for문 돌며 주어진 조건에 맞는 수를 ans에 추가
        for i in range(len(nums)):
            ans.append(nums[nums[i]])

        return ans