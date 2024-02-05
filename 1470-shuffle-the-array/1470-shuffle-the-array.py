class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        result = []

        # 반복문 n번 돌면서, nums[i], nums[i+n] 을 result에 차례로 추가
        for i in range(n):
            result.append(nums[i])
            result.append(nums[i+n])

        return result