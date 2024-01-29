class Solution {
public:
    string reversePrefix(string word, char ch) {
        // word에서 ch의 인덱스 찾아서 i에 저장
        int i;
        for (i=0; i<word.length(); i++) {
            if (word[i] == ch) {
                break;
            }
        }

        // word에서 ch가 등장하지 않는 경우
        if (i == word.length()) {
            return word;
        }

        // word에서 ch가 등장한 경우, 0부터 i까지 reverse (남은 칸은 자동으로 기존 word가 채워짐)
        std::reverse(word.begin(), word.begin()+i+1);
        return word;
    }
};