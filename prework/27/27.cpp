#include <stdio.h>
#include <stdlib.h>

// 定义链表节点的结构
struct Node {
    int data;           // 节点存储的数据
    struct Node* next;  // 指向下一个节点的指针
};

// 函数：删除值为 value 的节点
// 参数：head 是链表头指针，value 是要删除的值
// 返回：删除后的链表头指针
struct Node* deleteNode(struct Node* head, int value) {
    struct Node* current;  // 用于遍历链表的指针
    struct Node* prev;     // 记录当前节点的前一个节点

    // 情况1：链表为空，没东西可删
    if (head == NULL) {
        printf("链表为空，无法删除\n");
        return NULL;
    }

    // 情况2：要删除的恰好是头节点
    if (head->data == value) {
        current = head;        // 记住旧的头节点
        head = head->next;     // 头指针指向第二个节点
        free(current);         // 释放旧头节点的内存
        printf("已删除节点：%d\n", value);
        return head;           // 返回新的头指针
    }

    // 情况3：要删除的是中间或尾部的节点
    prev = head;              // prev 从头节点开始
    current = head->next;     // current 从第二个节点开始

    // 遍历链表，寻找值等于 value 的节点
    while (current != NULL) {
        if (current->data == value) {
            // 找到了！让前一个节点跳过当前节点
            prev->next = current->next;  // 关键操作：跳过 current
            free(current);               // 释放被删除节点的内存
            printf("已删除节点：%d\n", value);
            return head;
        }
        // 没找到，继续往后走
        prev = current;         // prev 前进一步
        current = current->next; // current 前进一步
    }

    // 遍历完了还没找到
    printf("未找到值为 %d 的节点\n", value);
    return head;
}

// 辅助函数：在链表尾部添加新节点
struct Node* append(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp;

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;  // 链表为空，新节点就是头
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;  // 找到最后一个节点
    }
    temp->next = newNode;   // 把新节点接在后面
    return head;
}

// 辅助函数：打印链表
void printList(struct Node* head) {
    struct Node* temp = head;
    printf("链表内容：");
    while (temp != NULL) {
        printf("%d → ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int deleteValue;

    // 创建链表：1 → 2 → 3 → 4 → 5
    head = append(head, 1);
    head = append(head, 2);
    head = append(head, 3);
    head = append(head, 4);
    head = append(head, 5);

    printf("删除前 ");
    printList(head);

    printf("\n请输入要删除的值：");
    scanf_s("%d", &deleteValue);

    head = deleteNode(head, deleteValue);  // 调用删除函数

    printf("删除后 ");
    printList(head);

    return 0;
}
