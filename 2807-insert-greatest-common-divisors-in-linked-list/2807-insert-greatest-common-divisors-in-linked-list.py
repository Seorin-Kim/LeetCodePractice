# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # head에서 시작
        curr = head

        # curr이 None이 아닌 동안,
        while curr is not None:
            # curr.next도 None이 아니면 (즉, 마지막 노드가 아니면),
            if curr.next is not None:
                # 현재노드와 다음노드의 값에서 최대공약수 찾기
                for i in range(min(curr.val, curr.next.val), 0, -1):
                    if curr.val % i == 0 and curr.next.val % i == 0:
                        gcd = i
                        break
                
                # 새로운 노드 만들어서 최대공약수 저장하고,
                newNode = ListNode()
                newNode.val = gcd
                # 새로운 노드의 next와 현재노드의 next를 업데이트하기
                newNode.next = curr.next
                curr.next = newNode
                
                # curr을 newNode.next (최대공약수 아닌 것들 중, 다음노드) 로 보내기
                curr = newNode.next

            # curr.next가 None이면 (즉, 마지막 노드라면),
            else:
                # curr을 curr.next (None) 로 보내기
                curr = curr.next
        
        return head