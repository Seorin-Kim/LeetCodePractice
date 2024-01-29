class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for (int &i : arr1) {
            int tmp = 0;
            for (int &j : arr2) {
                if (abs(i-j) <= d) {    // |i-j| <= d 인 경우가 등장하면 arr2 for문을 break
                    break;
                }
                tmp += 1;
            }

            if (tmp == arr2.size()) {   // arr2 for문을 모두 돌고 나왔으면 ans += 1
                ans += 1;
            }
        }
        return ans;
    }
};