#include <algorithm>
#include <string>
#include <vector>

using std::fill;
using std::string;
using std::vector;

class Solution_2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int lenDict = wordDict.size();
        const int lenS = s.size();
        // fill的用法一：传入iterator
        // vector<bool> reachable (lenS + 1);    // reachable[i] = true表示s[0...i-1]可以拆分为wordDict中的单词，+1是为了添加一个起始点，第一层for循环不需要对第一次进入该循环进行特判
        // fill(reachable.begin(), reachable.end(), false);
        // fill的用法二：
        bool reachable[lenS + 1];    // reachable[i] = true表示s[0...i-1]可以拆分为wordDict中的单词，+1是为了添加一个起始点，第一层for循环不需要对第一次进入该循环进行特判
        std::fill(reachable, reachable + lenS + 1, false);
        reachable[0] = true;
        for (int i = 0; i <= lenS; i++) {   // i 表示现在正在匹配 s[i ... lenS-1]
            if (reachable[i]) {
                // 与wordDict中每个单词进行匹配，并在可以匹配到的最远下标置true
                for (int j = 0; j < lenDict; j++) {
                    string word = wordDict[j];
                    if (i + word.size() <= lenS && s.substr(i, word.size()) == word) {
                        reachable[i + word.size()] = true;
                    }
                }
            }
        }
        return reachable[lenS];
    }
};

// std::fill: https://en.cppreference.com/w/cpp/algorithm/fill
// 
// C++ 区分std::fill和std::memset：https://www.cplusplus.com/forum/beginner/17491/
// 评论@kempofighter：
// There is a critical difference between std::fill and memset that is very important to understand. std::fill sets each element to the specified value. memset sets each byte to a specified value. In the case of filling values with 0 it doesn't matter much. If you wanted to initialize each element to a non-zero value memset isn't an option. It just wouldn't work. Also memset requires that you specify the array size as a number of bytes rather than number of elements. For non-char arrays memset requires that you calculate the number of bytes where std::fill is more intuitive.
// In fact the examples for std::fill in the earlier posts are incorrect. It should be: std::fill( array, array + 100, 0 );
// sizeof returns number of bytes not number of elements and would result in undefined behavior because std::fill would continue filling beyond the end of the integer array. sizeof would return 400 instead of 100 assuming that the int is 4 bytes (it probably is). Therefore it would cause std::fill to write 300 integers past the end of the array. I also recommend using a constant for defining the array size so that if the array changes you can update one line of code without worrying about creating defects.
