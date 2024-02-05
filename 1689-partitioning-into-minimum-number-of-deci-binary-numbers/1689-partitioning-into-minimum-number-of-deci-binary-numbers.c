int minPartitions(char* n) {
    // 각 자릿수 중 최대값을 찾으면 됨

    // 문자열로 이루어진 n을 분리해서 nums에 저장 (이때 int로 형변환)
    int nums[100000];
    for (int i=0; i<strlen(n); i++) {
        nums[i] = (int)(n[i] - '0');
    }

    // 그 중 최대값 찾아서 return
    int max = 0;
    for (int i=0; i<strlen(n); i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}