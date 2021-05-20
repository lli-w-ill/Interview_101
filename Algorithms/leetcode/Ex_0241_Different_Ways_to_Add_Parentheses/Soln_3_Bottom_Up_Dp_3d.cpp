#include <vector>
#include <string>
#include <iostream>
#include <sstream>  // istringstream

using std::vector;
using std::string;
using std::ostream;
using std::cout;
using std::endl;
using std::istringstream;

template<typename T>
ostream& operator<< (ostream &out, vector<T> &vec) {
    out << "[ ";
    for (T &num : vec) {
        out << num << " ";
    }
    out << "]";
    return out;
}

class Solution_3 {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> data;   // 存放操作数
        vector<char> ops;   // 存放操作符

        // 读取每个操作数和操作符
        int num;
        char op;
        istringstream ss (expression + "+");    // 在最后一个数字后面补一个 + 号，保证 data.size() == ops.size()，且 while 读取条件能够读到最后一个数字
        while (ss >> num && ss >> op) {
            data.push_back(num);
            ops.push_back(op);
        }

        cout << "data: " << data << endl;
        cout << "ops:  " << ops << endl;

        int size = data.size();

        // dp[j][i] 表示 .... (data[j] ops[j] data[j+1] ops[j+1] ... data[i] ops[i]) .... 中括号内的所有可能结果，用一个 vector<int> 来表示
        vector<vector<vector<int>>> dp (size, vector<vector<int>> (size, vector<int>()));

        for (int i = 0; i < size; i++) {
            for (int j = i; j >= 0; j--) {
                if (j == i) {
                    // 当前 .... (data[i] ops[i] data[i+1] ops[i+1] ... data[j] ops[j]) .... 只有一种可能，就是 data[i]
                    dp[j][i].push_back(data[i]);
                } else {
                    // 计算
                    for (int k = j; k < i; k++) {
                        // 遍历左边 A = (data[j] ops[j] data[j+1] ops[j+1] ... data[k] ops[k]) 所有可能的结果
                        for (auto left : dp[j][k]) {
                            // 继续遍历右边 B = (data[k+1] ops[k+1] data[k+2] ops[k+2] ... data[i] ops[i]) 所有可能的结果
                            for (auto right : dp[k+1][i]) {
                                // 由于 A 与 B 之间由 ops[k] 连接，所以根据 ops[k] 操作符，将不同的运算结果加入到 dp[j][i]
                                char op = ops[k];
                                int val;
                                switch (op) {
                                    case '+':
                                        val = left + right;
                                        break;
                                    case '-':
                                        val = left - right;
                                        break;
                                    case '*':
                                        val = left * right;
                                        break;
                                    default:
                                        val = 0;
                                        break;
                                }
                                dp[j][i].push_back(val);
                            }
                        }
                    }
                }
            }
        }

        return dp[0][size-1];

    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
