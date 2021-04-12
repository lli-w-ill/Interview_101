#include <cstdint>  // uint32_t

class Solution_1 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 31; i++) {  // 移动31次即可，因为第0位（最右边的一位）只需要31次左移就可以到达最高位（最左边的一位）
            res = res | (n & 1);

            res <<= 1;
            n >>= 1;
        }

        // 设置最后一位（n的最高位 -> res的最低位）
        res = res | (n & 1);

        return res;
    }
};
