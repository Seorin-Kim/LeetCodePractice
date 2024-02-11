class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        answer = 0
        flag = [[0]*26 for i in range(26)]      # 26x26 matrix

        # words를 돌면서,
        for word in words:
            # word[0], word[1]의 인덱스를 각각 i, j에 저장
            i = ord(word[0]) - ord('a')
            j = ord(word[1]) - ord('a')
            
            # word(즉, flag[i][j]) -> flag[j][i]가 이전에 있었으면, answer+=4 하고 flag[j][i]를 다시 0으로 만들기
            if flag[j][i] != 0:
                answer += 4
                flag[j][i] -= 1
            # word(즉, flag[i][j]) -> flag[j][i]가 이전에 없었으면, flag[i][j]+=1
            else:
                flag[i][j] += 1

        # 모두 돌고난 이후, 'aa' 같이 같은 문자로 이루어진 string이 존재하면
        for i in range(26):
            if flag[i][i] == 1:
                answer += 2     # answer+=2하고 break (가운데에 한번만 들어갈 수 있음)
                break
        
        return answer