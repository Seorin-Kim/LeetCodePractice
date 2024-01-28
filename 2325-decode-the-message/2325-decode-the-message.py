class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        key_list = [i for i in key if i.isalpha()]
        key_set = list(dict.fromkeys(key_list))

        result = []
        for c in message:
            if c == ' ':
                result.append(' ')
            else:
                result.append(chr(key_set.index(c) + 97))

        return ''.join(result)