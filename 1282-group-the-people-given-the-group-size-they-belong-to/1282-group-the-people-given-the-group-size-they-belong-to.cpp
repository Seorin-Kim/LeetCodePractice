class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result;
        int max_size = *max_element(groupSizes.begin(), groupSizes.end());  // groupSizes 중 최댓값

        // 1 ~ max_size 돌면서,
        // 해당 size 그룹에 들어가야 하는 사람을 tmp에 모두 저장하고
        // 각 tmp를 해당 size씩 나눠서 최종 결과인 result에 저장
        for (int i=1; i<max_size+1; i++) {
            vector<int> tmp;
            for (int j=0; j<groupSizes.size(); j++) {
                if (groupSizes[j] == i) {
                    tmp.push_back(j);
                }
            }
            for (int j=0; j<tmp.size()/i; j++) {
                result.push_back(vector<int>(tmp.begin()+(j*i), tmp.begin()+((j+1)*i)));
            }
        }

        return result;
    }
};