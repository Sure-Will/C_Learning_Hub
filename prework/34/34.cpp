#include <iostream>
#include <string>
using namespace std;

// 定义学生类
class Student {
    // 声明友元函数（告诉编译器：showGrade 函数可以访问我的私有成员）
    friend void showGrade(Student s);

private:
    string name;  // 学生姓名
    int score;    // 学生成绩

public:
    // 设置学生信息的函数
    void setInfo(string n, int s) {
        name = n;    // 设置姓名
        score = s;   // 设置成绩
    }

    // 获取姓名（用于显示）
    string getName() {
        return name;
    }
};

// 友元函数：输出成绩对应的等级
// 虽然定义在类外面，但可以访问 Student 的私有成员
void showGrade(Student s) {
    cout << "学生：" << s.name << "，成绩：" << s.score << "，等级：";

    // 根据成绩判断等级
    if (s.score >= 90) {
        cout << "优" << endl;
    }
    else if (s.score >= 80) {
        cout << "良" << endl;
    }
    else if (s.score >= 70) {
        cout << "中" << endl;
    }
    else if (s.score >= 60) {
        cout << "及格" << endl;
    }
    else {
        cout << "不及格" << endl;
    }
}

int main() {
    Student stu;        // 创建一个学生对象
    string name;        // 用来存储输入的姓名
    int score;          // 用来存储输入的成绩

    cout << "请输入学生姓名：";
    cin >> name;

    cout << "请输入学生成绩：";
    cin >> score;

    stu.setInfo(name, score);  // 设置学生信息

    showGrade(stu);  // 调用友元函数，输出等级

    return 0;
}