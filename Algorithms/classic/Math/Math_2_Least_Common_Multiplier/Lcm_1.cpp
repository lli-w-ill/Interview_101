int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 辗转相除法：求 a 和 b 的最小公倍数 (least common multiplier)
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

