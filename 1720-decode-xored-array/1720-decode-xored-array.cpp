class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        // arr[0]에 first 넣기
        vector<int> arr {first};

        // encoded 돌면서, arr의 값과 차례로 xor 계산
        for (int i=0; i<encoded.size(); i++) {
            arr.push_back(arr[i] ^ encoded[i]);
        }
  
        return arr;
    }
};