class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        # 띄어쓰기 기준으로 split
        words = s.split()

        # k번째 단어까지 띄어쓰기 붙여서 return
        return " ".join(words[:k])