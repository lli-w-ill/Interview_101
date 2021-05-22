#include <iostream>

using std::cout;
using std::endl;

// 在求得 a 和 b 的最大公因数的同时，求得其数字前面的系数 x 和 y，使得 x * a + y * b = gcd(a, b)
int extendedGcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1;
    int y1;
    int gcd = extendedGcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    cout << "a = " << a << ", b = " << b << ", x = " << x << ", y = " << y << ", x1 = " << x1 << ", y1 = " << y1 << endl;

    return gcd;
}

int main() {
    int x;
    int y;
    int gcd = extendedGcd(6, 20, x, y);

    cout << "最终结果：" << endl;
    cout << "gcd = " << gcd << ", a = 6, b = 20, x = " << x << ", y = " << y << endl;

    return 0;
}

// example: extendedGcd(6, 20)
//
// called function     a   b   x   y    x1   y1   gcd
// extendedGcd(6, 20)  6   20  -3  1    1    -3    2    ->  -3 * 6 + 1 * 20 = gcd = 2
// extendedGcd(20, 6)  20  6   1   -3   0    1     2
// extendedGcd(6, 2)   6   2   0   1    1    0     2
// extendedGcd(2, 0)   2   0   1   0    -    -     -            
//
// 注意：这个表格 called function 是从上往下填的，而 a, b, x, y, x1, y1, gcd 列是从下往上填的
