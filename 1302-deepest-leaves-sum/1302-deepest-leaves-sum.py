# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traverse(self, root: TreeNode, sumList: List[int], level: int) -> List[int]:
        if root is not None:
            # visit : sumList[level]에 본인 값 더하기
            sumList[level] += root.val

            # recursive 하게 들어갈 때 sumList[level+1]에 접근해야 하는데, 없으면 index 오류 -> sumList 한칸 늘리기
            if len(sumList) == level+1:
                sumList += [0]

            # left, right subtree 순회
            sumList = self.traverse(root.left, sumList, level+1)
            sumList = self.traverse(root.right, sumList, level+1)

        return sumList

    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        # sumList[i] : i-level 노드들의 합
        # ex1: sumList = [1,5,15,15,0] / ex2: sumList = [6,15,13,19,0]
        sumList = [0]

        # tree 순회
        sumList = self.traverse(root, sumList, 0)

        # 마지막에 0이 한번씩 더 붙어있을 것이므로, sumList[-2]의 값이 deepest leaves의 합
        return sumList[-2]