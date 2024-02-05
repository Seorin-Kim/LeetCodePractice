class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;

        // 반복문 n번 돌면서, nums[i], nums[i+n] 을 result에 차례로 추가
        for (int i=0; i<n; i++) {
            result.push_back(nums[i]);
            result.push_back(nums[i+n]);
        }

        return result;
    }
};