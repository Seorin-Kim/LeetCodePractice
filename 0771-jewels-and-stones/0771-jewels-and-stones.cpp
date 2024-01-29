class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // jewels의 각 letter를 jewel에 저장
        std::vector<char> jewel;
        for (char &c : jewels) {
            jewel.push_back(c);
        }

        // jewel를 각각 stones와 비교하면서 개수 세기
        int num = 0;
        for (char &i : jewel) {
            for (char &j : stones) {
                if (i == j) {
                    num += 1;
                }
            }
        }

        return num;
    }
};