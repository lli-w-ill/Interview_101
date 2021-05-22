// 辗转相除法：求 a 和 b 的最大公因数 (greatest common divisor)
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// example: gcd(6, 20)
// -> gcd(20, 6)
// -> gcd(6, 2)
// -> gcd(2, 0)
// -> 2
