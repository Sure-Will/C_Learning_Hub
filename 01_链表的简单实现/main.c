#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* 在链表头部插入一个新节点 */
Node *push_front(Node *head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        printf("malloc failed\n");
        return head;
    }
    new_node->data = value;
    new_node->next = head;
    return new_node;
}

/* 打印链表 */
void print_list(Node *head) {
    Node *cur = head;
    while (cur) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

/* 释放链表内存 */
void free_list(Node *head) {
    Node *cur = head;
    while (cur) {
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}

int main(void) {
    Node *head = NULL;

    /* 插入一些数据 */
    head = push_front(head, 3);
    head = push_front(head, 2);
    head = push_front(head, 1);

    /* 打印链表 */
    print_list(head);

    /* 释放内存 */
    free_list(head);

    return 0;
}