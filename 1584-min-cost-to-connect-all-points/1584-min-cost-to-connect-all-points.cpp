class Solution {
public:
    // Kruskal's Algorithm을 위한 find 함수
    int find(vector<int>& parent, int x) {
        // parent[x] == x 일 때까지 recursive 하게 호출해서 찾기
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    // Kruskal's Algorithm을 위한 union 함수
    void union_p(vector<int>& parent, int x, int y) {
        // x, y의 parent를 각각 찾아서 업데이트
        x = find(parent, x);
        y = find(parent, y);

        if (x < y) {
            parent[y] = x;
        } else {
            parent[x] = y;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        // manhattan distance를 weights로 하는 graph 저장하기
        // [weight, src, tgt] -> sort 간단히 하기 위해 weight를 맨 앞으로 가져감
        vector<vector<int>> graph;
        for (int i=0; i<points.size(); i++) {
            for (int j=0; j<points.size(); j++) {
                if (i != j) {
                    int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                    graph.push_back({dist,i,j});
                }
            }
        }

        /***********************************************/
        /* Minimum Spanning Tree (Kruskal's Algorithm) */
        /***********************************************/
        
        vector<int> parent;
        vector<vector<int>> mst;
        for (int i=0; i<points.size(); i++) {
            parent.push_back(i);
        }

        // weight를 기준으로 sort
        sort(graph.begin(), graph.end());

        // weight 작은 순서대로 edge를 돌면서,
        for (int i=0; i<graph.size(); i++) {
            // 해당 edge가 cycle을 만들지 않으면 (즉, src와 tgt의 parent가 다르면), mst에 추가
            if (find(parent, graph[i][1]) != find(parent, graph[i][2])) {
                union_p(parent, graph[i][1], graph[i][2]);
                mst.push_back(graph[i]);
            }
        }

        // mst의 edge를 돌면서 weight의 합 구해서 return
        int cost = 0;
        for (int i=0; i<mst.size(); i++) {
            cost += mst[i][0];
        }
        return cost;
    }
};