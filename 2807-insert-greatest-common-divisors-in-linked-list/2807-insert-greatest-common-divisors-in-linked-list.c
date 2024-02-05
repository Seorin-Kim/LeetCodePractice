/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    // head에서 시작
    struct ListNode* curr = head;

    // curr이 null이 아닌 동안,
    while (curr != 0) {
        // curr.next도 null이 아니면 (즉, 마지막 노드가 아니면),
        if (curr->next != 0) {
            // 현재노드와 다음노드의 값에서 최대공약수 찾기
            int gcd = 0;
            for (int i=((curr->val < curr->next->val) ? curr->val : curr->next->val); i>0; i--) {
                if ((curr->val % i == 0) && (curr->next->val % i == 0)) {
                    gcd = i;
                    break;
                }
            }

            // 새로운 노드 만들어서 최대공약수 저장하고,
            struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
            newNode->val = gcd;
            // 새로운 노드의 next와 현재노드의 next를 업데이트하기
            newNode->next = curr->next;
            curr->next = newNode;
            
            // curr을 newNode.next (최대공약수 아닌 것들 중, 다음노드) 로 보내기
            curr = newNode->next;
        }
        // curr.next가 null이면 (즉, 마지막 노드라면),
        else {
            // curr을 curr.next (null) 로 보내기
            curr = curr->next;
        }
    }

    return head;
}