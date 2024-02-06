class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // deck을 내림차순으로 정렬
        sort(deck.begin(), deck.end(), greater<>());

        deque<int> result {deck[0]};            // deque : 양방향 큐
        for (int i=1; i<deck.size(); i++) {
            // 큐를 오른쪽으로 한 칸씩 rotate
            result.push_front(result.back());
            result.pop_back();

            // 큐의 왼쪽(앞)에 추가
            result.push_front(deck[i]);
        }

        // deque -> vector 로 변환해서 return
        return {result.begin(), result.end()};
    }
};