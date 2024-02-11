/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int* traverse(struct TreeNode* root, int* sumList, int level) {
    if (root != 0) {
        // visit : sumList[level]에 본인 값 더하기
        sumList[level] += root->val;

        // left, right subtree 순회
        traverse(root->left, sumList, level+1);
        traverse(root->right, sumList, level+1);
    }
    return sumList;
}

int deepestLeavesSum(struct TreeNode* root) {
    // sumList[i] : i-level 노드들의 합
    // ex1: sumList = [1,5,15,15,0] / ex2: sumList = [6,15,13,19,0]
    int sumList[1000] = {0, };      // 0으로 초기화하면서 선언

    // tree 순회
    int* answer = traverse(root, sumList, 0);

    // sumList 중에서 0이 아닌 마지막 값을 return (1 <= node.val <= 100)
    for (int i=0; i<1000; i++) {
        if (answer[i] == 0) {
            return answer[i-1];
        }
    }
    return answer[0];   // return 맞춰주려고 그냥 붙인 것
}