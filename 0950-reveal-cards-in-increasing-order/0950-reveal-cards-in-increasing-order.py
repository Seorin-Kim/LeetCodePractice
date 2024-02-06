class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        # deck을 내림차순으로 정렬
        deck.sort(reverse=True)
    
        result = deque()    # deque : 양방향 큐, rotate 가능
        for n in deck:
            result.rotate()         # 큐를 오른쪽으로 한 칸씩 rotate
            result.appendleft(n)    # 큐의 왼쪽(앞)에 추가

        return result
    
    # deque([])
    # deque([17])

    # deque([17])
    # deque([13, 17])

    # deque([17, 13])
    # deque([11, 17, 13])

    # deque([13, 11, 17])
    # deque([7, 13, 11, 17])

    # deque([17, 7, 13, 11])
    # deque([5, 17, 7, 13, 11])

    # deque([11, 5, 17, 7, 13])
    # deque([3, 11, 5, 17, 7, 13])

    # deque([13, 3, 11, 5, 17, 7])
    # deque([2, 13, 3, 11, 5, 17, 7])