/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(int** graph, int graphSize, int* graphColSize, int curr, int* path, int* pathIdx, int** result, int* resultIdx, int* ptr) {
    // 현재 노드가 (n-1) 노드이면, 찾은 path를 result에 추가
    if (curr == graphSize-1) {
        // path의 복사본을 result에 추가 (이후에 path를 변경하면서 재사용할 것이기 때문)
        int *copyPath = (int *)malloc(sizeof(int) * (*pathIdx));
        for (int i=0; i<*pathIdx; i++) {
            copyPath[i] = path[i];
        }
        ptr[*resultIdx] = *pathIdx;
        result[*resultIdx] = copyPath;
        *resultIdx += 1;
        return;
    }
    
    // 현재 노드의 adj를 돌면서,
    for (int i=0; i<graphColSize[curr]; i++) {
        // path에 방문한 노드 추가
        path[*pathIdx] = graph[curr][i];
        *pathIdx += 1;
        // recursive하게 반복
        dfs(graph, graphSize, graphColSize, graph[curr][i], path, pathIdx, result, resultIdx, ptr);
        // result에 추가한 path는 지우기
        path[*pathIdx-1] = 0;
        *pathIdx -= 1;
    }
    return;
}

int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes) {
    int **result = (int **)malloc(sizeof(int*) * 10000);
    int *ptr = (int *)malloc(sizeof(int) * 10000);
    int resultIdx = 0;

    int *path = (int *)malloc(sizeof(int) * 20);
    path[0] = 0;
    int pathIdx = 1;

    // pathIdx, resultIdx는 함수 안에서 고쳐지기 때문에 포인터를 인자로 넘겨주기
    dfs(graph, graphSize, graphColSize, 0, path, &pathIdx, result, &resultIdx, ptr);

    *returnColumnSizes = ptr;
    *returnSize = resultIdx;

    return result;
}