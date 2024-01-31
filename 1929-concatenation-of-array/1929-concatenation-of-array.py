class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        ans = nums      # ans에 nums 복사
        ans += nums     # ans에 nums 한 번 더 더하기(concat)
        return ans