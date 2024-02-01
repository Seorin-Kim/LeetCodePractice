class Solution {
public:
    string defangIPaddr(string address) {
        vector<char> ans;

        // address를 차례로 돌면서,
        for (char &c : address) {
            if (c == '.') {             // '.' 등장하면 -> [.] 차례로 추가
                ans.push_back('[');
                ans.push_back(c);
                ans.push_back(']');
            } else {                    // 아니면 -> 문자 그대로 추가
                ans.push_back(c);
            }
        }

        // 결과를 string으로 변환해서 return
        std::stringstream result;
        for (char &c : ans) {
            result << c;
        }
        return result.str();
    }
};