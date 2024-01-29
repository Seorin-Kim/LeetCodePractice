class Solution:
    def makeSmallestPalindrome(self, s: str) -> str:
        # 문자열의 각 character 단위로 처리하기 위해 list로 변환
        s = list(s)

        # 문자열의 절반만 보면 되므로 (문자열길이//2) 번 반복
        for i in range(len(s)//2):
            if s[i] < s[-(i+1)]:    # s[i]의 알파벳이 앞순서면, s[-(i+1)]을 교체
                s[-(i+1)] = s[i]
            elif s[i] > s[-(i+1)]:  # s[i]의 알파벳이 뒷순서면, s[i]를 교체
                s[i] = s[-(i+1)]

        # list를 문자열로 고쳐서 return
        return ''.join(s)