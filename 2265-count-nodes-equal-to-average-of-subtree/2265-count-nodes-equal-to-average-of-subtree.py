# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # 주어진 root 기준으로, subtree들의 평균(소수점 버림)이 root.val과 같은지 확인하는 함수
    # 같으면 True, 다르면 False 반환
    def check(self, root: TreeNode):
        # sum, cnt 초기화 후, 총합과 노드개수 구하기
        sum = 0
        cnt = 0
        sum, cnt = self.traverseAvg(root, sum, cnt)

        # sum//cnt 해서 평균(소수점 버림)이 root.val과 같은지 비교
        if sum//cnt == root.val:
            return True
        else:
            return False

    # 주어진 root 기준으로, recursive하게 tree를 순회하면서 values의 합과 노드 개수를 구하는 함수
    # values의 총합은 sum으로, 노드의 개수는 cnt로 반환
    # -> not recursive하게 고쳐보기 (시간 남으면!!)
    def traverseAvg(self, root: TreeNode, sum: int, cnt: int):
        # inorder traverse
        if root is not None:
            sum, cnt = self.traverseAvg(root.left, sum, cnt)

            # visit : sum에 root.val 더하기, 노드개수 1 증가시키기
            sum += root.val
            cnt += 1

            sum, cnt = self.traverseAvg(root.right, sum, cnt)

        return sum, cnt

    def averageOfSubtree(self, root: TreeNode) -> int:
        ans = 0
        stack = []      # recursive 없이 traverse 하기 위한 stack
        curr = root     # root에서 시작

        while True:
            # left들을 모두 stack에 push
            if curr is not None :
                stack.append(curr)
                curr = curr.left
            
            # stack이 비어있지 않으면,
            elif len(stack) != 0:
                # 하나 pop 해서 check
                curr = stack.pop()
                if self.check(curr):
                    ans += 1
                
                # right subtree로 이동해서 반복
                curr = curr.right

            # curr도 null이고, stack이 비어있으면 순회 끝 -> break
            else:
                break

        return ans

