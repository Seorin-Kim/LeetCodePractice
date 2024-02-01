class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;

        // nums의 모든 원소를 ans에 추가 -> 2회 반복
        for (int i=0; i<2; i++) {
            for (int j=0; j<nums.size(); j++) {
                ans.push_back(nums[j]);
            }
        }

        return ans;
    }
};