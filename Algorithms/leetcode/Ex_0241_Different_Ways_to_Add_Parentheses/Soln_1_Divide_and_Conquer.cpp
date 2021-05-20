#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::ostream;
using std::cout;
using std::endl;
using std::string;

ostream& operator<< (ostream &out, vector<int> &vec) {
    out << "[ ";
    for (int &num : vec) {
        out << num << " ";
    }
    out << "]";
    return out;
}

class Solution_1 {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ways;

        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];

            if (c == '+' || c == '-' || c == '*') {
                // divide
                vector<int> left = diffWaysToCompute(expression.substr(0, i));      // 左半部分：expression[0 ... i-1]
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));    // 右半部分：expression[i+1 ... END]

                cout << "expression: " << expression << endl;
                cout << "left: " << left << endl;
                cout << "right: " << right << endl;

                // merge
                for (const int &l : left) {
                    for (const int &r : right) {
                        switch (c) {
                            case '+':
                                ways.push_back(l + r);
                                break;
                            case '-':
                                ways.push_back(l - r);
                                break;
                            case '*':
                                ways.push_back(l * r);
                                break;
                            default:
                                break;
                        }
                    }
                }
            }
        }

        // base case: expression 中只有数字，没有运算符号
        if (ways.empty()) {
            ways.push_back(stoi(expression));
        }

        return ways;
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
