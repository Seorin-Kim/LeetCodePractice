char* reversePrefix(char* word, char ch) {
    // word에서 ch의 인덱스 찾아서 i에 저장
    int i;
    for (i=0; i<strlen(word); i++) {
        if (word[i] == ch) {
            break;
        }
    }

    // word에서 ch가 등장하지 않는 경우
    if (i == strlen(word)) {
        return word;
    }

    // word에서 ch가 등장한 경우
    //// reversed (char)배열 초기화
    char reversed[250];
    for (int j=0; j<strlen(word); j++) {
        reversed[j] = word[j];
    }
    //// 0부터 i까지 reverse
    int c = 0;
    while (c <= i) {
        reversed[i-c] = word[c];
        c++;
    }

    // reversed (char)배열을 answer (char*)로 변환 후 return
    char *answer = (char *)malloc(strlen(word) + 1);
    for (int j=0; j<strlen(word); j++) {
        answer[j] = reversed[j];
    }
    answer[strlen(word)] = '\0';
    return answer;
}