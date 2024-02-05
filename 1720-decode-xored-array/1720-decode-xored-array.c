/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decode(int* encoded, int encodedSize, int first, int* returnSize) {
    // arr[0]에 first 넣기
    int *arr = (int *)malloc(sizeof(int) * (encodedSize+1));
    arr[0] = first;

    // encoded 돌면서, arr의 값과 차례로 xor 계산
    for (int i=0; i<encodedSize; i++) {
        arr[i+1] = arr[i] ^ encoded[i];
    }

    *returnSize = encodedSize + 1;
    return arr;
}