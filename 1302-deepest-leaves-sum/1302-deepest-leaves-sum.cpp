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
    void traverse(TreeNode* root, vector<int>& sumList, int level) {
        if (root != nullptr) {
            // visit : sumList[level]에 본인 값 더하기
            sumList[level] += root->val;

            // recursive 하게 들어갈 때 sumList[level+1]에 접근해야 하는데, 없으면 index 오류 -> sumList 한칸 늘리기
            if (sumList.size() == level+1){
                sumList.push_back(0);
            }

            // left, right subtree 순회
            traverse(root->left, sumList, level+1);
            traverse(root->right, sumList, level+1);
        }
    }

    int deepestLeavesSum(TreeNode* root) {
        // sumList[i] : i-level 노드들의 합
        // ex1: sumList = [1,5,15,15,0] / ex2: sumList = [6,15,13,19,0]
        vector<int> sumList {0};

        // tree 순회
        traverse(root, sumList, 0);

        // 마지막에 0이 한번씩 더 붙어있을 것이므로, sumList[-2]의 값이 deepest leaves의 합
        return sumList[sumList.size()-2];
    }
};