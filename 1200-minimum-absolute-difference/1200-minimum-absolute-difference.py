class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        # arr 정렬
        arr.sort()
        
        # 정렬된 arr에서 이웃한 정수끼리 차이 구해서, 그 중 최솟값 구하기
        minimum = 1e+12
        for i in range(len(arr)-1):
            diff = arr[i+1] - arr[i]
            if diff < minimum:
                minimum = diff

        # 이웃한 정수끼리의 차이가 minimum이라면, 해당 정수 쌍을 result에 저장
        result = []
        for i in range(len(arr)-1):
            if arr[i+1] - arr[i] == minimum:
                result.append([arr[i], arr[i+1]])
        
        return result