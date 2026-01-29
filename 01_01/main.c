#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int  stu_id;
    char name[20];
    char gender;
    int  chinese;
    int  math;
    int  english;
} Student;

/* ====== 业务逻辑层：观察内存（十六进制dump）====== */
static void dump_bytes(const void *ptr, size_t nbytes) {
    const unsigned char *p = (const unsigned char *)ptr;

    for (size_t i = 0; i < nbytes; ++i) {
        printf("%02X ", p[i]);
        if ((i + 1) % 16 == 0) puts("");
    }
    if (nbytes % 16 != 0) puts("");
}

/* ====== 业务逻辑层：只负责填充结构体字段（无I/O）====== */
static void fill_student(Student *s,
    int id,
    const char *name,
    char gender,
    int chinese,
    int math,
    int english) {
    if (!s) return;

    s->stu_id = id;

    /* name 是数组，不能用 = 赋值；要拷贝内容 */
    strcpy_s(s->name, sizeof(s->name), name);

    s->gender = gender;
    s->chinese = chinese;
    s->math = math;
    s->english = english;
}

/* ====== 输出层：只打印，不改数据 ====== */
static void print_student(const Student *s) {
    if (!s) {
        puts("[print_student] NULL student pointer.");
        return;
    }

    printf("Student information:\n");
    printf("\tID      : %d\n", s->stu_id);
    printf("\tName    : %s\n", s->name);
    printf("\tGender  : %c\n", s->gender);
    printf("\tChinese : %d\n", s->chinese);
    printf("\tMath    : %d\n", s->math);
    printf("\tEnglish : %d\n", s->english);
}

int main(void) {
    puts("=== Demo 1: malloc -> raw bytes -> memset(0) -> fill -> print ===");

    Student *p1 = (Student *)malloc(sizeof(Student));
    if (!p1) {
        puts("malloc failed!");
        return 1;
    }

    puts("[After malloc] Raw bytes of struct Student:");
    dump_bytes(p1, sizeof(Student));

    /* 防御性：使用前初始化（清零） */
    memset(p1, 0, sizeof(Student));
    puts("[After memset(0)] Raw bytes of struct Student:");
    dump_bytes(p1, sizeof(Student));

    fill_student(p1, 100, "dijia", 'm', 10, 20, 30);
    puts("[After fill_student] Print fields:");
    print_student(p1);

    free(p1);
    p1 = NULL;

    puts("\n=== Demo 2: calloc -> raw bytes -> fill -> print ===");

    Student *p2 = (Student *)calloc(1, sizeof(Student)); // 直接清零
    if (!p2) {
        puts("calloc failed!");
        return 1;
    }

    puts("[After calloc] Raw bytes of struct Student:");
    dump_bytes(p2, sizeof(Student));

    fill_student(p2, 200, "saiwen", 'f', 88, 90, 95);
    puts("[After fill_student] Print fields:");
    print_student(p2);

    free(p2);
    p2 = NULL;

    puts("\nDone.");
    return 0;
}
