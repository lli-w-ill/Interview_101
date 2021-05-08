#include <string>
#include <vector>
#include <set>
#include <iostream>

using std::string;
using std::vector;
using std::set;
using std::cout;
using std::endl;

class Tle_1 {
public:
    vector<string> removeInvalidParentheses(string s) {
        bruteForce(s, 0, 0, 0, "", 0);
        vector<string> res (resSet.size());
        copy(resSet.begin(), resSet.end(), res.begin());
        return res;
    }

private:
    set<string> resSet;
    int leastRemoveTimes = INT_MAX;  // 记录当前删除括号最小的次数

    void bruteForce(string s, int index, int leftBracket, int rightBracket, string cur, int removeTimes) {
        cout << index << ", " << leftBracket << ", " << rightBracket << ", " << cur << ", " << removeTimes << endl;
        // 终点
        if (cur.size() + removeTimes == s.size() && leftBracket == rightBracket) {
            if (removeTimes < leastRemoveTimes) {
                // 找到新的需要更少删除括号次数的方法，删除之前的所有结果，重新记录结果
                leastRemoveTimes = removeTimes;
                resSet.clear();
                string temp = cur;
                resSet.insert(temp);
                return;
            } else if (removeTimes == leastRemoveTimes) {
                string temp = cur;
                resSet.insert(temp);
                return;
            } else if (removeTimes > leastRemoveTimes) {
                return;
            }
        }
        if (index >= s.size()) {
            return;
        }
        
        // invalid case
        if (leftBracket < rightBracket) {
            return;
        }

        if (s[index] != '(' && s[index] != ')') {
            // 如果不是左括号或者是右括号，则保留，继续看下一个字符
            bruteForce(s, index + 1, leftBracket, rightBracket, cur + s[index], removeTimes);
        } else if (s[index] == '(') {
            // 不省略当前 (
            bruteForce(s, index + 1, leftBracket + 1, rightBracket, cur + "(", removeTimes);

            // 省略当前 (
            bruteForce(s, index + 1, leftBracket, rightBracket, cur, removeTimes + 1);
        } else if (s[index] == ')') {
            // 不省略当前 )
            bruteForce(s, index + 1, leftBracket, rightBracket + 1, cur + ")", removeTimes);

            // 省略当前 )
            bruteForce(s, index + 1, leftBracket, rightBracket, cur, removeTimes + 1);
        }
    }
};
