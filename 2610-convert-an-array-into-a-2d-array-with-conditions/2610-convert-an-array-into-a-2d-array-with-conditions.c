/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
bool check(int* arr, int arrSize, int val) {
    for (int i=0; i<arrSize; i++) {
        if (arr[i] == val) {
            return true;
        }
    }
    return false;
}

int** findMatrix(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **result = (int **)malloc(sizeof(int *) * numsSize);
    int *ptr = (int *)malloc(sizeof(int) * numsSize);
    int size = numsSize;
    int row = 0;                // result의 행 나타내기 위한 변수

    // result에 원소를 넣을 때마다 nums에서 해당 원소를 제거, nums의 원소가 0보다 큰 동안 반복
    while (size > 0) {
        result[row] = (int *)malloc(sizeof(int) * numsSize);     // result에 행 추가
        int idx = 0;
        // nums를 돌면서, distinct한 값들만 result[row]에 추가
        for (int i=0; i<size; i++) {
            for (int j=0; j<=idx; j++) {
                if (check(result[row], idx, nums[i])) {
                    continue;
                }
                result[row][idx++] = nums[i];
            }
        }
        

        // result[row]에 추가된 값들을 nums에서 제거
        for (int i=0; i<idx; i++) {
            // nums를 돌면서, 처음 등장하는 result[row][i] 값을 nums에서 지우고 break
            for (int j=0; j<size; j++) {
                if (nums[j] == result[row][i]) {
                    for (int k=j; k<size-1; k++) {
                        nums[k] = nums[k+1];
                    }
                    size--;
                    break;
                }
            }
        }
        
        // 행 번호 업데이트
        // result[row] = realloc(result[row], sizeof(int) * idx);
        ptr[row] = idx;
        row++;
    }

    *returnColumnSizes = ptr;
    *returnSize = row;

    return result;
}