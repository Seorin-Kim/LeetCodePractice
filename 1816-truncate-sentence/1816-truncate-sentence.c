char* truncateSentence(char* s, int k) {
    int cntSpace = 0;   // 공백 개수 세는 변수
    int idx = 0;        // 어디까지 반환해야 하는지 return하기 위한 변수

    for (int i=0; i<strlen(s); i++) {
        if (s[idx] == ' ') {        // 공백이면 cntSpace++
            cntSpace++;
        }
        if (cntSpace == k) {        // 공백 개수가 k개이면 break
            break;
        }

        idx++;                      // string을 어디까지 읽었는지 표시
    }

    char *answer = (char *)malloc(idx+1);
    for (int i=0; i<idx; i++) {
        answer[i] = s[i];
    }
    answer[idx] = '\0';
    return answer;                  // return s[:idx]
}