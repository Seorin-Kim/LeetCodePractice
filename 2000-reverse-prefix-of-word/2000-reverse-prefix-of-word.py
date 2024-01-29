class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        # ch가 word에 없는 경우
        if ch not in word:
            return word
        
        # ch가 word에 있는 경우
        i = 0
        for c in word:
            # ch가 등장하면 break -> i가 ch의 인덱스
            if c == ch:
                break
            i += 1
        # i부터 거꾸로 + (i+1)부터 순서대로
        result = word[i::-1] + word[i+1:]
        return result
        