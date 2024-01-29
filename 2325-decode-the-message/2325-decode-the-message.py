class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        # key의 각 알파벳을 중복없이, 순서대로 key_set에 저장
        key_set = []
        for c in key:
            if c.isalpha() and c not in key_set:
                key_set.append(c)

        # message를 key_set과 매칭하여 result에 저장
        result = []
        for c in message:
            if c == ' ':    # 띄어쓰기 처리
                result.append(' ')
            else:           # key_set에서의 인덱스 찾아서, 'a'의 유니코드에 더하기 -> 해당 알파벳의 유니코드
                result.append(chr(key_set.index(c) + ord('a')))

        # result의 각 원소를 문자열로 이어붙이기
        return ''.join(result)