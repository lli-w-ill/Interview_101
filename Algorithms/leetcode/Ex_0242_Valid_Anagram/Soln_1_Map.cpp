#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;

class Solution_1 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int size = s.size();
        unordered_map<char, int> occurrence;

        // 扫描 s,t，递增 s[i] 字符的次数，递减 t[i] 字符的次数，最后检查 map 中是否所有值都是0
        for (int i = 0; i < size; i++) {
            char si = s[i];
            char ti = t[i];

            if (occurrence.count(si)) {
                occurrence[si] ++;
            } else {
                occurrence[si] = 1;
            }

            if (occurrence.count(ti)) {
                occurrence[ti] --;
            } else {
                occurrence[ti] = -1;
            }
        }

        for (const auto &[key, value] : occurrence) {   // c++17
            if (value != 0) {
                return false;
            }
        }
        return true;
        
    }
};

