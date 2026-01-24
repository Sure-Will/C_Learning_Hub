#include <stdio.h>

#define STACK_CAPACITY 10

typedef struct {
	int data[STACK_CAPACITY];
	int top; // 指向下一个可放位置，当前元素个数也等于top
} Stack;

void init(Stack *s) {
	s->top = 0;
}

int is_empty(const Stack *s) {
	return s->top == 0;
}

int is_full(const Stack *s) {
	return s->top == STACK_CAPACITY;
}

int push(Stack *s, int value) {
	if (is_full(s)) return 0; // 栈满
	s->data[s->top] = value;
	s->top++;
	return 1;
}

int pop(Stack *s, int *out) {
	if (is_empty(s)) return 0; // 栈空
	s->top--;
	*out = s->data[s->top];
	return 1;
}

int peek(const Stack *s, int *out) {
	if (is_empty(s)) return 0;
	*out = s->data[s->top - 1];
	return 1;
}

int main(void) {
	Stack s;
	init(&s);

	int choice = 0;

	while (1) {
		printf("\n1-入栈 2-出栈 3-查看栈顶 4-退出\n");
		printf("请选择: ");

		if (scanf_s("%d", &choice) != 1) {
			printf("输入无效，结束。\n");
			return 0;
		}

		if (choice == 1) {
			int x;
			printf("输入要入栈的整数: ");
			if (scanf_s("%d", &x) != 1) {
				printf("输入无效。\n");
				return 0;
			}

			if (push(&s, x)) {
				printf("入栈成功。\n");
			}
			else {
				printf("栈已满，无法入栈。\n");
			}
		}
		else if (choice == 2) {
			int x;
			if (pop(&s, &x)) {
				printf("出栈元素: %d\n", x);
			}
			else {
				printf("栈为空，无法出栈。\n");
			}
		}
		else if (choice == 3) {
			int x;
			if (peek(&s, &x)) {
				printf("栈顶元素: %d\n", x);
			}
			else {
				printf("栈为空。\n");
			}
		}
		else if (choice == 4) {
			printf("退出。\n");
			break;
		}
		else {
			printf("无效选项。\n");
		}
	}

	return 0;
}

