#include <string>
#include <map>

using std::string;
using std::map;
using std::to_string;

class Solution_1 {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        
        map<int, string> m;
        m[1] = "1";
        
        for (int i = 2; i <= n; i++) {
            // 扫描 m[i-1]
            int count = 1;
            char ch = m[i-1][0];
            string res = "";
            for (int j = 1; j < m[i-1].size(); j++) {
                if (m[i-1][j] != ch) {
                    res += to_string(count) + ch;
                    // 更新
                    count = 1;
                    ch = m[i-1][j];
                } else {
                    count += 1;
                }
            }
            // 加上最后一个
            res += to_string(count) + ch;
            m[i] = res;
        }

        return m[n];
    }
};
