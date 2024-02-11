class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string &word : words) {
            int flag = 1;        // palindromic 인지 나타내는 변수
            for (int i=0; i<word.size()/2; i++) {
                // 글자 한번이라도 다르면 flag = 0 으로 만들고 break (다음 word로 넘어가기)
                if (word[i] != word[word.size()-1-i]) {
                    flag = 0;
                    break;
                }
            }

            // flag == 1 이면 palindromic
            if (flag) {
                return word;
            }
        }

        // 모두 아니면 empty string
        return "";
    }
};