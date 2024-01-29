char * makeSmallestPalindrome(char * s){
    // 문자열의 각 character 단위로 처리하기 위해 char 배열로 변환
    char s_arr[1000];
    for (int i=0; i<strlen(s); i++) {
        s_arr[i] = s[i];
    }

    // 문자열의 절반만 보면 되므로 (문자열길이//2) 번 반복
    for (int i=0; i<strlen(s)/2; i++) {
        if (s_arr[i] < s_arr[strlen(s)-1-i]) {           // s[i]의 알파벳이 앞순서면, s[strlen(s)-1-i]을 교체
            s_arr[strlen(s)-1-i] = s_arr[i];
        } else if (s_arr[i] > s_arr[strlen(s)-1-i]) {    // s[i]의 알파벳이 뒷순서면, s[i]를 교체
            s_arr[i] = s_arr[strlen(s)-1-i];
        }
    }

    // s_arr (char)배열을 answer (char*)로 변환 후 return
    char *answer = (char *)malloc(strlen(s) + 1);
    for (int i=0; i<strlen(s); i++) {
        answer[i] = s_arr[i];
    }
    answer[strlen(s)] = '\0';
    return answer;
}