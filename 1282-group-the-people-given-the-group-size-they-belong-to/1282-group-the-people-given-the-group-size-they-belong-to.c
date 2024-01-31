/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes) {
    // groupSizes 중 최댓값
    int max_size = groupSizes[0];
    for (int i=1; i<groupSizesSize; i++) {
        if (groupSizes[i] > max_size) {
            max_size = groupSizes[i];
        }
    }

    // 정답 그룹의 포인터를 저장하기 위한 result 동적할당
    // 정답 그룹의 각 크기를 저장하기 위한 ptr 동적할당
    int **result = (int **)malloc(sizeof(int *) * 500);
    int *ptr = (int *)malloc(sizeof(int) * 500);
    int resultIdx = 0;

    // 1 ~ max_size 돌면서,
    for (int i=1; i<max_size+1; i++) {
        int *tmp = (int *)malloc(sizeof(int) * 500);
        int tmpIdx = 0;

        for (int j=0; j<groupSizesSize; j++) {  // 해당 size(i) 그룹에 들어가야 하는 사람을 tmp에 모두 저장하고
            if (groupSizes[j] == i) {
                tmp[tmpIdx++] = j;
            }
        }
        
        for (int j=0; j<tmpIdx/i; j++) {        // 각 tmp를 해당 size(i)씩 나눠서 최종 결과인 result에 저장
            result[resultIdx] = (int *)malloc(sizeof(int) * i);
            for (int k=0; k<i; k++) {
                result[resultIdx][k] = tmp[j*i + k];
            }
            ptr[resultIdx] = i;
            resultIdx++;
        }
    }

    *returnColumnSizes = ptr;
    *returnSize = resultIdx;

    return result;
}