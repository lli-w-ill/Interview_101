#include <map>

using std::map;

class Tle_2 {
public:
    int countPrimes(int n) {
        // key: 2 ~ n-1
        // val: true if prime, false if not
        map<int, bool> mp;
        for (int i = 2; i < n; i++) {
            mp[i] = true;
        }

        mp[2] = true;
        int count = 0;  // 计数 0 ~ curNum-1 一共有多少素数
        int curNum = 2;
        while (curNum < n) {
            if (mp[curNum]) {
                // 将 2 ~ n 之间所有 curNum 的倍数置为「非素数」
                for (int i = 2; i * curNum < n; i++) {
                    mp[i * curNum] = false;
                }
                count ++;
            }
            curNum ++;
        }

        return count;
    }
};

// 参考之前账号提交记录

