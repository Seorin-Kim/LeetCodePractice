class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;

        // i,j 차례대로 for문 돌면서,
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<nums.size(); j++) {
                // 조건에 맞으면 ans++
                if ((i < j) && (nums[i] == nums[j])) {
                    ans++;
                }
            }
        }

        return ans;
    }
};