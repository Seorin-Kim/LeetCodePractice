/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 함수에서 반환값 2개로 하기 위한 구조체 정의
typedef struct ret {
    int *ans;
    int cnt;
} ret;

// preorder 실제로 시행하는 recursive 함수 정의
// visit 표시하기 위한 ans, ans의 원소 개수를 표시하기 위한 cnt
ret traverse(int* ans, struct TreeNode* root, int cnt) {
    ret returnValue;
    returnValue.ans = ans;
    returnValue.cnt = cnt;

    if (root != 0) {
        returnValue.ans[returnValue.cnt] = root->val;
        returnValue.cnt += 1;

        returnValue = traverse(returnValue.ans, root->left, returnValue.cnt);
        returnValue = traverse(returnValue.ans, root->right, returnValue.cnt);
    }
    return returnValue;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *ans = (int *)malloc(sizeof(int) * 100);
    int cnt = 0;
    
    ret returnValue;
    returnValue = traverse(ans, root, cnt);
    
    *returnSize = returnValue.cnt;
    return returnValue.ans;
}