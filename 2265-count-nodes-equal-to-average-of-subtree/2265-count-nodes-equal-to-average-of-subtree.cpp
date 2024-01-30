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
    // 주어진 root 기준으로, subtree들의 평균(소수점 버림)이 root.val과 같은지 확인하는 함수
    // 같으면 True, 다르면 False 반환
    bool check(TreeNode* root) {
        // sum, cnt 초기화 후, 총합과 노드개수 구하기
        int sum = 0;
        int cnt = 0;
        pair<int,int> avg;
        avg = traverseAvg(root, sum, cnt);

        // 총합/노드개수 해서 평균(소수점 버림)이 root.val과 같은지 비교
        if (avg.first/avg.second == root->val) {
            return true;
        } else {
            return false;
        }
    }

    // 주어진 root 기준으로, recursive하게 tree를 순회하면서 values의 합과 노드 개수를 구하는 함수
    // values의 총합은 avg.first로, 노드의 개수는 avg.second로 반환
    // -> not recursive하게 고쳐보기 (시간 남으면!!)
    pair<int,int> traverseAvg(TreeNode* root, int sum, int cnt) {
        pair<int,int> avg;
        avg.first = sum;
        avg.second = cnt;
        
        // inorder traverse
        if (root != nullptr) {
            avg = traverseAvg(root->left, avg.first, avg.second);
            
            // visit : 총합에 root.val 더하기, 노드개서 1 증가시키기
            avg.first += root->val;
            avg.second++;

            avg = traverseAvg(root->right, avg.first, avg.second);
        }
        return avg;
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        stack<TreeNode*> s;         // recursive 없이 traverse 하기 위한 stack
        TreeNode* curr = root;      // root에서 시작

        while (true) {
            // left들을 모두 stack에 push
            if (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            
            // stack이 비어있지 않으면,
            else if (!s.empty()) {
                // 하나 pop 해서 check
                curr = s.top();
                s.pop();
                if (check(curr)) {
                    ans++;
                }
                // right subtree로 이동해서 반복
                curr = curr->right;
            }

            // curr도 null이고, stack이 비어있으면 순회 끝 -> break
            else {
                break;
            }
        }

        return ans;
    }
};