int numJewelsInStones(char* jewels, char* stones) {
    // jewels의 각 letter를 jewel에 저장
    char jewel[50];
    for (int i=0; i<strlen(jewels); i++) {
        jewel[i] = jewels[i];
    }

    // jewel를 각각 stones와 비교하면서 개수 세기
    int num = 0;
    for (int i=0; i<strlen(jewels); i++) {
        for (int j=0; j<strlen(stones); j++) {
            if (jewel[i] == stones[j]) {
                num++;
            }
        }
    }

    return num;
}