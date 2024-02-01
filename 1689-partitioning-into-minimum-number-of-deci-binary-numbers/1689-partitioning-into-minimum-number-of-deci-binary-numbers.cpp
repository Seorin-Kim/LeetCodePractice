class Solution {
public:
    int minPartitions(string n) {
        // 각 자릿수 중 최대값을 찾으면 됨

        // 문자열로 이루어진 n을 분리해서 nums에 저장 (이때 int로 형변환)
        vector<int> nums;
        for (char &c : n) {
            nums.push_back((int)(c)-'0');
        }

        // 그 중 최대값 찾아서 int로 변환해서 return
        return *max_element(nums.begin(), nums.end());
    }
};