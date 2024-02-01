class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        // 첫번째 연산은 0^pref[0] 을 해야하므로, 제일 앞에 0 추가
        pref.insert(pref.begin(), 0);

        // pref 돌면서, 다음 것과 ^ 연산한 결과를 arr에 저장
        vector<int> arr;
        for (int i=0; i<pref.size()-1; i++) {
            arr.push_back(pref[i]^pref[i+1]);
        }

        return arr;
        
    }
};