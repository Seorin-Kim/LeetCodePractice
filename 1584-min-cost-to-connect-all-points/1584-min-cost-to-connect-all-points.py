class Solution:
    # Kruskal's Algorithm을 위한 find 함수
    def find(self, parent: List[int], x: int) -> int:
        # parent[x] == x 일 때까지 recursive 하게 호출해서 찾기
        if parent[x] != x:
            parent[x] = self.find(parent, parent[x])
        return parent[x]
    
    # Kruskal's Algorithm을 위한 union 함수
    def union(self, parent: List[int], x: int, y: int):
        # x, y의 parent를 각각 찾아서 업데이트
        x = self.find(parent, x)
        y = self.find(parent, y)

        if x < y:
            parent[y] = x
        else:
            parent[x] = y
        
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        # manhattan distance를 weights로 하는 graph 저장하기
        # [src, tgt, weight]
        graph = []
        for i in range(len(points)):
            for j in range(len(points)):
                if i != j:
                    dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1])
                    graph.append([i,j,dist])
        

        ###############################################
        # Minimum Spanning Tree (Kruskal's Algorithm) #
        ###############################################

        parent = [i for i in range(len(points))]
        mst = []

        # weight를 기준으로 sort
        graph.sort(key=lambda x: x[2])

        # weight 작은 순서대로 edge를 돌면서,
        for edge in graph:
            # 해당 edge가 cycle을 만들지 않으면 (즉, src와 tgt의 parent가 다르면), mst에 추가
            if self.find(parent, edge[0]) != self.find(parent, edge[1]):
                self.union(parent, edge[0], edge[1])
                mst.append(edge)

        # mst의 edge를 돌면서 weight의 합 구해서 return
        cost = 0
        for edge in mst:
            cost += edge[2]
        return cost