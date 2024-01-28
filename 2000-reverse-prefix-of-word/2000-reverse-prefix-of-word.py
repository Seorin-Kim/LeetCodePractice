class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        if ch not in word:
            return word
        
        i = 0
        for c in word:
            if c == ch:
                break
            i += 1
        
        result = word[i::-1] + word[i+1:]
        return result
        