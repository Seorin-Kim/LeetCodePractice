class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;      // profit의 최댓값
        int min_price = 10000;   // 현재까지의 최소 price

        for (int i=0; i<prices.size(); i++) {
            min_price = min({min_price, prices[i]});                 // 현재까지의 최소 price 계속 업데이트하기
            max_profit = max({max_profit, prices[i]-min_price});     // 현재 p와 min_price로 구한 profit이 max인지 확인해서 계속 업데이트하기
        }

        return max_profit;
    }
};