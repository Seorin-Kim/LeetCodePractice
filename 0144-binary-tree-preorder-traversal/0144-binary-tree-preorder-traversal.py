# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # preorder 실제로 시행하는 recursive 함수 정의
    # visit 표시하기 위한 ans 를 반환
    def traverse(self, ans: List[int], root: Optional[TreeNode]):
        if root is not None:
            ans.append(root.val)
            ans = self.traverse(ans, root.left)
            ans = self.traverse(ans, root.right)
        return ans

    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        ans = self.traverse(ans, root)
        return ans