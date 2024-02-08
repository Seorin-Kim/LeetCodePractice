/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define TRUE 1
#define FALSE 0
#define ERROR -1

typedef int boolean;
typedef int element;
typedef struct __dequeType {
    element *data;
    int front;
    int rear;
} Deque;

void init_deque(Deque *q, int dequeSize) {
    q->data = (element *)malloc(sizeof(element) * dequeSize);
    q->front = 0;
    q->rear = 0;
}
boolean is_empty(Deque *q) {
    if (q->front == q->rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}
boolean is_full(Deque *q, int dequeSize) {
    if (((q->rear+1) % dequeSize) == q->front) {
        return TRUE;
    } else {
        return FALSE;
    }
}
element get_front(Deque *q, int dequeSize) {
    if (is_empty(q)) {
        printf("deque is empty.\n");
        return ERROR;
    }
    return q->data[(q->front+1) % dequeSize];
}
element get_rear(Deque *q) {
    if (is_empty(q)){
        printf("deque is empty.\n");
        return ERROR;
    }
    return q->data[q->rear];
}
void add_front(Deque *q, element data, int dequeSize) {
    if (is_full(q, dequeSize)) {
        printf("deque is full.\n");
        return;
    }

    q->data[q->front] = data;
    q->front = (q->front - 1 + dequeSize) % dequeSize;
    return;
}
void add_rear(Deque *q, element data, int dequeSize) {
    if (is_full(q, dequeSize)) {
        printf("deque is full.\n");
        return;
    }

    q->rear = (q->rear + 1) % dequeSize;
    q->data[q->rear] = data;
}
element delete_front(Deque *q, int dequeSize) {
    if (is_empty(q)) {
        printf("deque is empty.\n");
        return ERROR;
    }

    element tmp = get_front(q, dequeSize);
    q->front = (q->front + 1) % dequeSize;
    return tmp;
}
element delete_rear(Deque *q, int dequeSize) {
    if (is_empty(q)) {
        printf("deque is empty.\n");
        return ERROR;
    }

    element tmp = get_rear(q);
    q->rear = (q->rear - 1 + dequeSize) % dequeSize;
    return tmp;
}

// qsort를 위한 비교 함수
int compare(void const *a, void const *b) {
    return *(int *)b - *(int *)a;
}

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {
    // deck을 내림차순으로 정렬
    qsort(deck, deckSize, sizeof(int), compare);

    // deque : 양방향 큐 -> 초기화
    Deque *result = (Deque *)malloc(sizeof(Deque));
    int dequeSize = deckSize + 1;
    init_deque(result, dequeSize);
    add_front(result, deck[0], dequeSize);

    for (int i=1; i<deckSize; i++) {
        // 큐를 오른쪽으로 한 칸씩 rotate
        add_front(result, get_rear(result), dequeSize);
        delete_rear(result, dequeSize);

        // int i = (result->front+1) % dequeSize;
        // while (i != result->rear) {
        //     printf("%d ", result->data[i]);
        //     i = (i+1) % dequeSize;
        // }
        // printf("%d ", result->data[i]);

        // 큐의 왼쪽(앞)에 추가
        add_front(result, deck[i], dequeSize);
    }

    if (is_empty(result)) {
        printf("deque is empty.\n");
        return ERROR;
    }

    // deque(result) -> array(answer) 로 변환해서 return
    int *answer = (int *)malloc(sizeof(int) * dequeSize);
    int i = (result->front+1) % dequeSize;
    
    int answerIdx = 0;
    while (i != result->rear) {
        answer[answerIdx++] = result->data[i];
        i = (i+1) % dequeSize;
    }
    answer[answerIdx] = result->data[i];

    *returnSize = deckSize;
    return answer;
}