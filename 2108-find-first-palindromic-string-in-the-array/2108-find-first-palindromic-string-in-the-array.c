char* firstPalindrome(char** words, int wordsSize) {
    for (int i=0; i<wordsSize; i++) {
        int flag = 1;        // palindromic 인지 나타내는 변수
        for (int j=0; j<strlen(words[i])/2; j++) {
            // 글자 한번이라도 다르면 flag = 0 으로 만들고 break (다음 word로 넘어가기)
            if (*(words[i]+j) != *(words[i]+(strlen(words[i])-1-j))) {
                flag = 0;
                break;
            }
        }

        // flag == 1 이면 palindromic
        if (flag) {
            return words[i];
        }
    }

    // 모두 아니면 empty string
    return "";
}