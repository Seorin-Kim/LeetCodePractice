/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // preorder 실제로 시행하는 recursive 함수 정의
    // visit 표시하기 위한 ans 를 반환
    vector<int> traverse(vector<int> &ans, TreeNode* root) {
        if (root != nullptr) {
            ans.push_back(root->val);
            ans = traverse(ans, root->left);
            ans = traverse(ans, root->right);
        }
        return ans;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        ans = traverse(ans, root);
        return ans;
    }
};