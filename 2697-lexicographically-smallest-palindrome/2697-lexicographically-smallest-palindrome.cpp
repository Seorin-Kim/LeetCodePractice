class Solution {
public:
    string makeSmallestPalindrome(string s) {
        // 문자열의 각 character 단위로 처리하기 위해 vector로 변환
        vector<char> s_vec;
        for (char &c : s) {
            s_vec.push_back(c);
        }

        // 문자열의 절반만 보면 되므로 (문자열길이//2) 번 반복
        for (int i=0; i<s_vec.size()/2; i++) {
            if (s_vec[i] < s_vec[s_vec.size()-1-i]) {           // s[i]의 알파벳이 앞순서면, s[s_vec.size()-1-i]을 교체
                s_vec[s_vec.size()-1-i] = s_vec[i];
            } else if (s_vec[i] > s_vec[s_vec.size()-1-i]) {    // s[i]의 알파벳이 뒷순서면, s[i]를 교체
                s_vec[i] = s_vec[s_vec.size()-1-i];
            }
        }

        // 결과를 string으로 변환해서 return
        std::stringstream result;
        for (char &c : s_vec) {
            result << c;
        }
        return result.str();
    }
};