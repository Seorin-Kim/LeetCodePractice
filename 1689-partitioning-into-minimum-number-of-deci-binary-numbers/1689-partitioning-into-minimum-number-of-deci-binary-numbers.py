class Solution:
    def minPartitions(self, n: str) -> int:
        # 각 자릿수 중 최대값을 찾으면 됨

        # 문자열로 이루어진 n을 분리해서 nums에 저장
        nums = []
        for i in n:
            nums.append(i)
        
        # 그 중 최대값 찾아서 int로 변환해서 return
        return int(max(nums))