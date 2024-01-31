class Solution:
    def findArray(self, pref: List[int]) -> List[int]:
        # 첫번째 연산은 0^pref[0] 을 해야하므로, 제일 앞에 0. 추가
        pref.insert(0, 0)

        # pref 돌면서, 다음 것과 ^ 연산한 결과를 arr에 저장
        arr = []
        for i in range(len(pref)-1):
            arr.append(pref[i]^pref[i+1])

        return arr
        