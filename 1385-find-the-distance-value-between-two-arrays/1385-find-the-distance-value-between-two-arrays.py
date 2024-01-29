class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        ans = 0
        for i in arr1:
            tmp = 0
            for j in arr2:
                if abs(i-j) <= d:   # |i-j| <= d 인 경우가 등장하면 arr2 for문을 break
                    break
                tmp += 1
            
            if tmp == len(arr2):    # arr2 for문을 모두 돌고 나왔으면 ans += 1
                ans += 1
        
        return ans