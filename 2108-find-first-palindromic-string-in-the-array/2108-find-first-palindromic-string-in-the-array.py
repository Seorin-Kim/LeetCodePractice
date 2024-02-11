class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            flag = 1        # palindromic 인지 나타내는 변수
            for i in range(len(word)//2):
                # 글자 한번이라도 다르면 flag = 0 으로 만들고 break (다음 word로 넘어가기)
                if word[i] != word[len(word)-1-i]:
                    flag = 0
                    break
            
            # flag == 1 이면 palindromic
            if flag:
                return word
        
        # 모두 아니면 empty string
        return ""        
