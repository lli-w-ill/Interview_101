#include <string>   // string, stoi
#include <deque>

using std::string;
using std::deque;
using std::stoi;

class Solution_1 {
public:
    int calculate(string s) {
        // 由于计算 * / 时用到的是 stack 的性质，最后计算 + - 时需要从左向右，所以用到了 queue 的性质，所以选用 deque
        deque<int> numDeque;
        deque<char> opDeque;

        int i = 0;
        int size = s.size();
        while (i < size) {
            if (isdigit(s[i])) {
                // 如果是数字一直读到下一个非数字字符
                string numStr = "";
                while (i < size && isdigit(s[i])) {
                    numStr += s[i];
                    i ++;
                }
                // 将字符串转为 int 型后入栈
                string::size_type sz;   // alias of size_t
                // cout << "numStr: " << numStr << endl;
                numDeque.push_back(stoi(numStr, &sz, 10));
            } else {
                // 如果是乘号或除号，取栈顶数字做作为「左操作数」，下一个数字作为「右操作数」，直接将结果push到numDeque
                if (s[i] == '*' || s[i] == '/') {
                    // 栈顶元素就是「左操作数」
                    int leftOperand = numDeque.back();
                    numDeque.pop_back();

                    // 首先保存操作符（因为下面 i 会变化）
                    char op = s[i];

                    // cout << "leftOperand: " << leftOperand << endl;

                    // 读取「右操作数」
                    i ++;
                    // 排除 * 或 / 后面的空格
                    while (i < size && s[i] == ' ') {
                        i ++;
                    }
                    // 一直读到下一个非数字字符
                    string rightOperandStr;
                    while (i < size && isdigit(s[i])) {
                        rightOperandStr += s[i];
                        i ++;
                    }
                    // 将右操作数转为int 型
                    string::size_type sz;   // alias of size_t
                    int rightOperand = stoi(rightOperandStr, &sz, 10);
                    // cout << "rightOperand: " << rightOperand << endl; 

                    if (op == '*') {
                        numDeque.push_back(leftOperand * rightOperand);
                    } else if (op == '/') {
                        numDeque.push_back(leftOperand / rightOperand);
                    }
                } else if (s[i] == '+' || s[i] == '-') {
                    opDeque.push_back(s[i]);
                    i ++;
                }
            }

            // 每次 i 递增需要递增到下一个非空格字符
            while (i < size && s[i] == ' ') {
                i ++;
            }
        }

        // 判断 s 是否只含有空格的“空串”
        if (numDeque.empty()) {
            return 0;
        }

        // 计算完表达式中的乘法和除法运算后，从后向前顺序计算加减结果
        while (!opDeque.empty()) {
            int leftOperand = numDeque.front();
            numDeque.pop_front();
            int rightOperand = numDeque.front();
            numDeque.pop_front();

            char op = opDeque.front();
            opDeque.pop_front();

            if (op == '+') {
                numDeque.push_front(leftOperand + rightOperand);
            } else if (op == '-') {
                numDeque.push_front(leftOperand - rightOperand);
            }
        }

        // 最终结果应该就是栈顶元素
        return numDeque.front();
    }
};
