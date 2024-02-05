class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        # arr[0]에 first 넣기
        arr = [first]

        # encoded 돌면서, arr의 값과 차례로 xor 계산
        for i in range(len(encoded)):
            arr.append(arr[i] ^ encoded[i])
            
        return arr