class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 0 ~ n 을 돌면서
        for (int i=0; i<nums.size()+1; i++) {
            // nums에 없으면 return
            if (find(nums.begin(), nums.end(), i) == nums.end()) {
                return i;
            }
        }
        return nums.size();
    }
};