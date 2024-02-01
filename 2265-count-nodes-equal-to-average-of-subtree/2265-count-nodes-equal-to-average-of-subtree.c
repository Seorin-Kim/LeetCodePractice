/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// stack 구현
// 함수 : isEmpty(), isFull(), push(val), pop()
#define STACK_SIZE 1000
struct TreeNode* stack[STACK_SIZE];
int top = -1;
int isEmpty() {
    if (top < 0) {
        return true;
    } else {
        return false;
    }
}
int isFull() {
    if (top >= STACK_SIZE-1) {
        return true;
    } else {
        return false;
    }
}
void push(struct TreeNode* val) {
    if (isFull()) {
        printf("stack is full.\n");
    } else {
        stack[++top] = val;
    }
}
struct TreeNode* pop() {
    if (isEmpty()) {
        printf("stack is empty.\n");
        return 0;
    } else {
        return stack[top--];
    }
}

// 함수에서 반환값 2개로 하기 위한 구조체 정의
typedef struct ret {
    int sum;
    int cnt;
} ret;


// 주어진 root 기준으로, recursive하게 tree를 순회하면서 values의 합과 노드 개수를 구하는 함수
// values의 총합은 avg.sum로, 노드의 개수는 avg.cnt로 반환
// -> not recursive하게 고쳐보기 (시간 남으면!!)
ret traverseAvg(struct TreeNode* root, int sum, int cnt) {
    ret avg;
    avg.sum = sum;
    avg.cnt = cnt;
    
    // inorder traverse
    if (root != 0) {
        avg = traverseAvg(root->left, avg.sum, avg.cnt);
        
        // visit : 총합에 root.val 더하기, 노드개서 1 증가시키기
        avg.sum += root->val;
        avg.cnt++;

        avg = traverseAvg(root->right, avg.sum, avg.cnt);
    }
    return avg;
}

// 주어진 root 기준으로, subtree들의 평균(소수점 버림)이 root.val과 같은지 확인하는 함수
// 같으면 True, 다르면 False 반환
bool check(struct TreeNode* root) {
    // sum, cnt 초기화 후, 총합과 노드개수 구하기
    int sum = 0;
    int cnt = 0;
    ret avg;
    avg = traverseAvg(root, sum, cnt);

    // 총합/노드개수 해서 평균(소수점 버림)이 root.val과 같은지 비교
    if (avg.sum / avg.cnt == root->val) {
        return true;
    } else {
        return false;
    }
}

int averageOfSubtree(struct TreeNode* root) {
    int ans = 0;
    struct TreeNode* curr = root;      // root에서 시작

    while (true) {
        // left들을 모두 stack에 push
        if (curr != 0) {
            push(curr);
            curr = curr->left;
        }
        
        // stack이 비어있지 않으면,
        else if (!isEmpty()) {
            // 하나 pop 해서 check
            curr = pop();
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