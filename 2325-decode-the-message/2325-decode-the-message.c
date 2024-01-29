// char 배열인 arr에서 val이 있는지 확인해서, 있으면 인덱스를, 없으면 -1을 return
int findIdx(char* arr, int size, char val) {
    for (int i=0; i<size; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1;
}

char* decodeMessage(char* key, char* message) {
    // key의 각 알파벳을 중복없이, 순서대로 key_set에 저장
    char key_set[27];
    int idx = 0;
    for (int i=0; i<strlen(key); i++) {
        if (key[i] != ' ' && findIdx(key_set, (int)(sizeof(key_set)/sizeof(char)), key[i]) == -1) {
            key_set[idx] = key[i];
            idx++;
        }
    }
    for (int i=0; i<27; i++) {
        printf("%c ", key_set[i]);
    }

    // message를 key_set과 매칭하여 decode에 저장
    char decode[2000];
    idx = 0;
    for (int i=0; i<strlen(message); i++) {
        if (message[i] == ' ') {
            decode[idx] = ' ';
            idx++;
        } else {        // findIdx로 인덱스 찾기, 'a'의 유니코드 더하기
            decode[idx] = findIdx(key_set, (int)(sizeof(key_set)/sizeof(char)), message[i]) + (int)('a');
            idx++;
        }
    }

    // decode (char)배열을 answer (char*)로 변환 후 return
    char *answer = (char *)malloc(strlen(message) + 1);
    for (int i=0; i<strlen(message); i++) {
        answer[i] = decode[i];
    }
    answer[strlen(message)] = '\0';
    return answer;
}