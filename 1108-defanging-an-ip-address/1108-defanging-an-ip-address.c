

char * defangIPaddr(char * address){
    char ans[100];

    // address를 차례로 돌면서,
    int idx = 0;
    for (int i=0; i<strlen(address); i++) {
        if (address[i] == '.') {    // '.' 등장하면 -> [.] 차례로 추가
            ans[idx++] = '[';
            ans[idx++] = '.';
            ans[idx++] = ']';
        } else {                    // 아니면 -> 문자 그대로 추가
            ans[idx++] = address[i];
        }
    }

    // 결과를 string으로 변환해서 return
    char *answer = (char *)malloc(idx+1);
    for (int i=0; i<idx; i++) {
        answer[i] = ans[i];
    }
    answer[idx] = '\0';
    return answer;
}