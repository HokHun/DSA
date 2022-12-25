#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX_ITEMS 10
typedef struct {
    int priority;
    int value;
} Item;
typedef struct {
    Item items[MAX_ITEMS];
    int front, rear;
} PriorityQueue;
int compare(int a, int b) { // Sử dụng hàm so sánh ưu tiên tùy ý
    return a > b;
}
void enqueue(PriorityQueue *queue, int priority, int value) {
    if (queue->rear == MAX_ITEMS) {// Hàng đợi đã đầy, không thể thêm phần tử nữa
        return;
    }
        Item item;
        item.priority = priority;
        item.value = value;
        int i;
    for (i = queue->rear; i > queue->front && compare(queue->items[i - 1].priority, priority); i--) {
        // Dịch các phần tử có ưu tiên thấp hơn sang sau
        queue->items[i] = queue->items[i - 1];
    }
        // Thêm phần tử mới tại vị trí đã tìm được
        queue->items[i] = item;
        queue->rear++;
    }
        Item dequeue(PriorityQueue *queue) {
    if (queue->front == queue->rear) {
        //Hàng đợi rỗng, không thể lấy phần tử nữa
        return (Item) { .priority = -1, .value = -1 };
    }
        return queue->items[queue->front++];
}
bool is_empty(PriorityQueue *queue) {
    return queue->front == queue->rear;
}
bool is_full(PriorityQueue *queue) {
    return queue->rear == MAX_ITEMS;
}
// cách 1
// int main(void) {
//   PriorityQueue queue;
//   queue.front = 0;
//   queue.rear = 0;
//   // Thêm các phần tử vào hàng đợi
//   enqueue(&queue, 3, 1);
//   enqueue(&queue, 2, 2);
//   enqueue(&queue, 1, 3);
//   // Lấy các phần tử từ hàng đợi
//   Item item = dequeue(&queue);
//   printf("%d %d\n", item.priority, item.value);
//   item = dequeue(&queue);
//   printf("%d %d\n", item.priority, item.value);
// }
// cách 2
int main() {
    PriorityQueue queue;
    queue.front = 0;
    queue.rear = 0;
    int n;
    printf("Nhap so n: ");
    scanf("%d", &n);
    // Nhập các phần tử vào hàng đợi
    int i;
    for (i = 0; i < n; i++) {
        int priority, value;
        printf("Nhap muc do uu tien va gia tri phan tu thu %d:\n", i + 1);
        scanf("%d%d", &priority, &value);
        enqueue(&queue, priority, value);
    }
    // Lấy các phần tử từ hàng đợi
    while (!is_empty(&queue)) {
        Item item = dequeue(&queue);
        printf("%d %d\n", item.priority, item.value);
    }
    // Kiểm tra trạng thái của hàng đợi
    if (is_empty(&queue)) {
        printf("Hang doi rong\n");
    }
    if (is_full(&queue)) {
        printf("Hang doi day\n");
    }
    return 0;
}
