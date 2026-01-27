#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

void addFamily(map<string, vector<string>>& families, const string& surname)
{
    families[surname]; // 如果不存在，会自动创建一个空的vector作为值
}

void addChild(map<string, vector<string>>& families, const string& surname, const string& child)
{
    families[surname].push_back(child); // 不存在则先创建该家庭，再把孩子名字加入vector
}

void printFamilies(const map<string, vector<string>>& families)
{
    cout << "\n当前家庭信息如下：" << endl;
    for (map<string, vector<string>>::const_iterator it = families.begin(); it != families.end(); ++it)
    {
        cout << "姓氏：" << it->first << "，孩子：";
        const vector<string>& kids = it->second; // 取出孩子列表
        if (kids.empty())
        {
            cout << "(暂无)";
        }
        else
        {
            for (size_t i = 0; i < kids.size(); i++)
            {
                cout << kids[i];
                if (i + 1 != kids.size()) cout << ", ";
            }
        }
        cout << endl;
    }
}

int main()
{
    map<string, vector<string>> families; // key: 姓氏，value: 孩子名字列表

    int choice; // 用来保存菜单选择
    string surname; // 用来保存输入的姓氏
    string child;   // 用来保存输入的孩子名字

    while (1)
    {
        cout << "\n====== 家庭管理菜单 ======" << endl;
        cout << "1. 添加新家庭（只添加姓氏）" << endl;
        cout << "2. 给家庭添加孩子" << endl;
        cout << "3. 打印所有家庭信息" << endl;
        cout << "0. 退出" << endl;
        cout << "请输入你的选择：";

        if (!(cin >> choice)) // 读取菜单选项
        {
            cout << "输入错误，程序结束。" << endl;
            return 0;
        }

        if (choice == 0) break;

        if (choice == 1)
        {
            cout << "请输入家庭姓氏：";
            cin >> surname;
            addFamily(families, surname); // 添加新家庭
            cout << "已添加家庭：" << surname << endl;
        }
        else if (choice == 2)
        {
            cout << "请输入家庭姓氏：";
            cin >> surname;
            cout << "请输入孩子名字：";
            cin >> child;
            addChild(families, surname, child); // 给家庭添加孩子
            cout << "已给 " << surname << " 家添加孩子：" << child << endl;
        }
        else if (choice == 3)
        {
            printFamilies(families); // 打印当前结果
        }
        else
        {
            cout << "无效选择，请重新输入。" << endl;
        }
    }

    cout << "已退出。" << endl;
    return 0;
}
