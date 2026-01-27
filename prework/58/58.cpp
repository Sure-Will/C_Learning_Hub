#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main()
{
    vector<string> v; // 用vector存不重复单词（需要手动判断）
    set<string> s;    // 用set存不重复单词（自动去重）

    cout << "请输入若干单词（结束请输入 Ctrl+Z 再回车）：\n";
    string word;

    while (cin >> word)
    {
        // --- vector：手动去重 ---
        bool exists = false; // 标记word是否已存在
        for (size_t i = 0; i < v.size(); i++)
        {
            if (v[i] == word) // 如果找到重复
            {
                exists = true;
                break;
            }
        }
        if (!exists)
            v.push_back(word); // 不重复才放进去

        // --- set：自动去重 ---
        s.insert(word); // 插入重复元素不会报错，只是不会插进去
    }

    cout << "\nvector 里（不重复）：";
    for (size_t i = 0; i < v.size(); i++)
        cout << " " << v[i];
    cout << endl;

    cout << "set 里（不重复且自动排序）：";
    for (set<string>::iterator it = s.begin(); it != s.end(); ++it)
        cout << " " << *it;
    cout << endl;

    return 0;
}
