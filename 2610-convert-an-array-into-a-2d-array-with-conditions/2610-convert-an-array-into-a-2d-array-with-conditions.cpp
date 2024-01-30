class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> result;
        int row = 0;                // result의 행 나타내기 위한 변수

        // result에 원소를 넣을 때마다 nums에서 해당 원소를 제거, nums의 원소가 0보다 큰 동안 반복
        while (nums.size() > 0) {
            result.push_back({});   // result에 행 추가
            // nums를 돌면서, distinct한 값들만 result[row]에 추가
            for (int i=0; i<nums.size(); i++) {
                if (std::find(result[row].begin(), result[row].end(), nums[i]) == result[row].end()) {
                    result[row].push_back(nums[i]);
                }
            }

            // result[row]에 추가된 값들을 nums에서 제거
            for (int i=0; i<result[row].size(); i++) {
                // nums를 돌면서, 처음 등장하는 result[row][i] 값을 nums에서 지우고 break
                for (int j=0; j<nums.size(); j++) {
                    if (nums[j] == result[row][i]) {
                        nums.erase(nums.begin() + j);
                        break;
                    }
                }
            }
            
            // 행 번호 업데이트
            row++;
        }

        return result;
    }
};