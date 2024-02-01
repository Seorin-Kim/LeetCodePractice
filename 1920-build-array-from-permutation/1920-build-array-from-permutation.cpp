class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;

        // for문 돌며 주어진 조건에 맞는 수를 ans에 추가
        for (int i=0; i<nums.size(); i++) {
            ans.push_back(nums[nums[i]]);
        }

        return ans;
    }
};