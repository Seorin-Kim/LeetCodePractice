// Kruskal's Algorithm을 위한 find 함수
int find(int* parent, int x) {
    // parent[x] == x 일 때까지 recursive 하게 호출해서 찾기
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

// Kruskal's Algorithm을 위한 union 함수
void union_p(int* parent, int x, int y) {
    // x, y의 parent를 각각 찾아서 업데이트
    x = find(parent, x);
    y = find(parent, y);

    if (x < y) {
        parent[y] = x;
    } else {
        parent[x] = y;
    }
}

// qsort를 위한 비교 함수
int compare(void const *a, void const *b) {
    return (*(int *)a) - (*(int *)b);
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    // manhattan distance를 weights로 하는 graph 저장하기
    // [weight, src, tgt] -> sort 간단히 하기 위해 weight를 맨 앞으로 가져감
    int graph[1000000][3];
    int idx = 0;
    for (int i=0; i<pointsSize; i++) {
        for (int j=0; j<pointsSize; j++) {
            if (i != j) {
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                graph[idx][0] = dist;
                graph[idx][1] = i;
                graph[idx][2] = j;
                idx++;
            }
        }
    }

    /***********************************************/
    /* Minimum Spanning Tree (Kruskal's Algorithm) */
    /***********************************************/
    
    int parent[pointsSize];
    int cost = 0;           // mst 따로 저장 안하고, cost만 계산
    for (int i=0; i<pointsSize; i++) {
        parent[i] = i;
    }

    // weight를 기준으로 sort
    qsort(graph, idx, sizeof(graph[0]), compare);

    // weight 작은 순서대로 edge를 돌면서,
    for (int i=0; i<idx; i++) {
        // 해당 edge가 cycle을 만들지 않으면 (즉, src와 tgt의 parent가 다르면), mst에 추가
        if (find(parent, graph[i][1]) != find(parent, graph[i][2])) {
            union_p(parent, graph[i][1], graph[i][2]);
            cost += graph[i][0];
        }
    }

    return cost;
}