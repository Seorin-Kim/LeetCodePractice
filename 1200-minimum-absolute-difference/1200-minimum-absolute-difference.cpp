class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // arr 정렬
        sort(arr.begin(), arr.end());

        // 정렬된 arr에서 이웃한 정수끼리 차이 구해서, 그 중 최솟값 구하기
        int minimum = std::numeric_limits<int>::max();
        for (int i=0; i<arr.size()-1; i++) {
            int diff = arr[i+1] - arr[i];
            if (diff < minimum) {
                minimum = diff;
            }
        }

        // 이웃한 정수끼리의 차이가 minimum이라면, 해당 정수 쌍을 result에 저장
        std::vector<vector<int>> result;
        for (int i=0; i<arr.size()-1; i++) {
            if (arr[i+1]-arr[i] == minimum) {
                result.push_back({arr[i], arr[i+1]});
            }
        }

        return result;
    }
};