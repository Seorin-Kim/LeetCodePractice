class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        result = []
        max_size = max(groupSizes)      # groupSizes 중 최댓값

        # 1 ~ max_size 돌면서,
        # 해당 size 그룹에 들어가야 하는 사람을 tmp에 모두 저장하고
        # 각 tmp를 해당 size씩 나눠서 최종 결과인 result에 저장
        for i in range(1, max_size+1):
            tmp = []
            for j in range(len(groupSizes)):
                if groupSizes[j] == i:
                    tmp.append(j)
            for j in range(len(tmp)//i):
                result.append(tmp[j*i : (j+1)*i])
        
        return result