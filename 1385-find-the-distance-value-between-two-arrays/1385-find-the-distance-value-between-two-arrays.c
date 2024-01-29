int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    int ans = 0;
    for (int i=0; i<arr1Size; i++) {
        int tmp = 0;
        for (int j=0; j<arr2Size; j++) {
            if (abs(arr1[i]-arr2[j]) <= d) {     // |i-j| <= d 인 경우가 등장하면 arr2 for문을 break
                break;
            }
            tmp++;
        }

        if (tmp == arr2Size) {                  // arr2 for문을 모두 돌고 나왔으면 ans++
            ans++;
        }
    }

    return ans;
}