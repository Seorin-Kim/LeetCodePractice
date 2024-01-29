/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// qsort를 위한 비교 함수
int compare(void const *a, void const *b) {
    return *(int *)a - *(int *)b;
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    // arr 정렬
    qsort(arr, arrSize, sizeof(int), compare);

    // 정렬된 arr에서 이웃한 정수끼리 차이 구해서, 그 중 최솟값 구하기
    // 차이의 최솟값을 가지는 정수 쌍의 개수 cnt에 저장하기
    int cnt = 0;
    int minimum = INT_MAX;
    for (int i=0; i<arrSize-1; i++) {
        int diff = arr[i+1] - arr[i];
        if (diff < minimum) {
            minimum = diff;
            cnt = 1;
        } else if (diff == minimum) {
            cnt++;
        }
    }

    // 정답 정수 쌍의 포인터를 저장하기 위한 answer 동적할당
    // 정답 정수 쌍의 각 크기를 저장하기 위한 ptr 동적할당
    int **answer = (int **)malloc(sizeof(int *) * cnt);
    int *ptr = (int *)malloc(sizeof(int) * cnt);
    // 이웃한 정수끼리의 차이가 minimum이라면, 해당 정수 쌍을 answer에 저장
    int idx = 0;
    for (int i=0; i<arrSize-1; i++) {
        if (arr[i+1]-arr[i] == minimum) {
            answer[idx] = (int *)malloc(sizeof(int) * 2);   // answer 중 하나의 공간이 하나의 정답 정수 쌍을 가리키도록 동적할당
            answer[idx][0] = arr[i];
            answer[idx][1] = arr[i+1];
            ptr[idx] = 2;
            idx++;
        }
    }

    *returnColumnSizes = ptr;
    *returnSize = cnt;

    return answer;
}