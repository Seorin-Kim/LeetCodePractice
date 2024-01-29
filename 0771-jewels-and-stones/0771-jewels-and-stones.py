class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        # jewels의 각 letter를 jewel에 저장
        jewel = []
        for j in jewels:
            jewel.append(j)

        # jewel를 각각 stones와 비교하면서 개수 세기
        num = 0
        for j in jewel:
            for s in stones:
                if j == s:
                    num += 1
        return num