bool isStrictlyPalindromic(int n) {
    // base b를 2부터 n-2까지 반복
    for (int b=2; b<n-1; b++) {
        int num = n;            // n이 소실되면 안되므로 num에 복사해서 사용
        int base_n[100];        // b진법으로 변환한 숫자 저장하기 위한 배열 (역순으로 저장됨, 여기에서는 굳이 뒤집을 필요 x)

        // b로 나눈 몫이 0이 될 때까지, 반복해서 b로 나누기
        // 몫은 다음 나눗셈에 사용, 나머지는 b진법 변환을 위한 숫자로 사용
        int idx = 0;
        while (num > 0) {
            int remain = num % b;
            num = num / b;
            base_n[idx++] = remain;
        }

        // base_n의 양끝을 비교하며 대칭 여부 결정
        int size = sizeof(base_n)/sizeof(int);
        for (int i=0; i<size/2; i++) {
            if (base_n[i] != base_n[size-1-i]) {   // 한 번이라도 다르면 False
                return false;
            }
        }
    }
    // 모두 통과하면 True
    return true;
}