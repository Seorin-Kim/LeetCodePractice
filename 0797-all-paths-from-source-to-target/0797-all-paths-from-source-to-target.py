class Solution:
    def dfs(self, graph: List[List[int]], curr: int, path: List[int], result: List[List[int]]):
        # 현재 노드가 (n-1) 노드이면, 찾은 path를 result에 추가
        if curr == len(graph)-1:
            result.append(path[:])              # path의 복사본을 result에 추가 (이후에 path를 변경하면서 재사용할 것이기 때문)
            return
        
        # 현재 노드의 adj를 돌면서,
        for v in graph[curr]:
            path.append(v)                      # path에 방문한 노드 추가
            self.dfs(graph, v, path, result)    # recursive하게 반복
            path.pop()                          # result에 추가한 path는 지우기
    
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        result = []
        self.dfs(graph, 0, [0], result)
        return result