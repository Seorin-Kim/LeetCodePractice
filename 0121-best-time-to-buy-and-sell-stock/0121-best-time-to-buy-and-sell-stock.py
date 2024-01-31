class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0      # profit의 최댓값
        min_price = 10000   # 현재까지의 최소 price

        for p in prices:
            min_price = min(min_price, p)               # 현재까지의 최소 price 계속 업데이트하기
            max_profit = max(max_profit, p-min_price)   # 현재 p와 min_price로 구한 profit이 max인지 확인해서 계속 업데이트하기

        return max_profit