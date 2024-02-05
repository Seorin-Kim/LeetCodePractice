class Solution {
public:
    string truncateSentence(string s, int k) {
        int cntSpace = 0;   // 공백 개수 세는 변수
        int idx = 0;        // 어디까지 반환해야 하는지 return하기 위한 변수

        for (char &c : s) {
            if (c == ' ') {         // 공백이면 cntSpace++
                cntSpace++;
            }
            if (cntSpace == k) {    // 공백 개수가 k개이면 break
                break;
            }

            idx++;                  // string을 어디까지 읽었는지 표시
        }


        return s.substr(0, idx);    // return s[:idx]
    }
};