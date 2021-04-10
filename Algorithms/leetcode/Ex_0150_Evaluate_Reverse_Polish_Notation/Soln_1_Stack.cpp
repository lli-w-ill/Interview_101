#include <string>
#include <cctype>   // std::cctype
#include <stack>
#include <vector>

using std::string;
using std::isdigit;
using std::stack;
using std::vector;


class Solution_1 {
public:
    int evalRPN(vector<string>& tokens) {
        int size = tokens.size();
        if (size == 1) {
            return stoi(tokens[0]);
        }

        stack<int> sk;
        for (int i = 0; i < size; i++) {
            string cur = tokens[i];
            if (this->isInteger(cur)) {
                sk.push(stoi(cur));
            } else {
                // 取栈顶的两个数字然后做运算，最后将结果再放回栈
                // 因为题目说逆波兰表达式总是有效，所以 sk.size() >= 2
                int num1 = sk.top();
                sk.pop();
                int num2 = sk.top();
                sk.pop();

                // c++ switch 不能用于 string，详见参考网站
                // switch(cur) {
                //     case "+":
                //         sk.push(num2 + num1);
                //         break;
                //     case "-":
                //         sk.push(num2 - num1);
                //         break;
                //     case "*":
                //         sk.push(num2 * num1);
                //         break;
                //     case "/":
                //         sk.push(num2 / num1);
                //         break;
                //     default:
                //         break;
                // }

                if (cur == "+") {
                    sk.push(num2 + num1);
                } else if (cur == "-") {
                    sk.push(num2 - num1);
                } else if (cur == "*") {
                    sk.push(num2 * num1);
                } else if (cur == "/") {
                    sk.push(num2 / num1);
                }
            }
        }

        return sk.top();
    }

private:
    bool isInteger(const string &s) {
        string::const_iterator it = s.begin();
        if (*it == '-') {
            it ++;
            // 需要检查是不是 s 只是一个单纯的减号，而不是数字前的负号
            if (s.size() == 1) {
                return false;
            }
        }
        while (it != s.end() && isdigit(*it)) {
            it ++;
        }
        return it == s.end();
    }
};

// 参考（检查string是不是合法数字）：https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
// 参考（c++ switch 不能用于 string）：https://stackoverflow.com/questions/650162/why-the-switch-statement-cannot-be-applied-on-strings
