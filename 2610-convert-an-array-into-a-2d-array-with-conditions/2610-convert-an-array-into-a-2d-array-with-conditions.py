class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        result = []
        row = 0         # result의 행 나타내기 위한 변수

        # result에 원소를 넣을 때마다 nums에서 해당 원소를 제거, nums의 원소가 0보다 큰 동안 반복
        while (len(nums) > 0):
            result.append([])   # result에 행 추가
            # nums를 돌면서, distinct한 값들만 result[row]에 추가
            for n in nums:
                if n not in result[row]:
                    result[row].append(n)
            
            # result[row]에 추가된 값들을 nums에서 제거
            # (nums.remove(n) 함수 : nums에서 가장 처음 등장한 n을 제거)
            for n in result[row]:
                nums.remove(n)
            
            # 행 번호 업데이트
            row += 1
        
        return result
