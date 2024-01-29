class Solution {
public:
    string decodeMessage(string key, string message) {
        // key의 각 알파벳을 중복없이, 순서대로 key_set에 저장
        std::vector<char> key_set;
        for (char &c : key) {
            // 알파벳인 경우 && key_set에 없는 경우
            if ((c != ' ') && (std::find(key_set.begin(), key_set.end(), c) == key_set.end())) {
                key_set.push_back(c);
            }
        }

        // message를 key_set과 매칭하여 result에 저장
        std::stringstream result;
        for (char &c : message) {
            if (c == ' ') {
                result << ' ';
            } else {                // std::find() - key_set.begin() 으로 인덱스 찾기, 'a'의 유니코드 더하기
                result << static_cast<char>(std::find(key_set.begin(), key_set.end(), c) - key_set.begin() + static_cast<int>('a'));
            }
        }

        return result.str();
    }
};