/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    if (n == 0)
        return 1.0;
    else if (n > 0) {
        if (n % 2 == 0) {
            const mid = myPow(x, Math.floor(n / 2));
            return mid * mid;
        } else {
            const mid = myPow(x, Math.floor((n - 1) / 2));
            return x * mid * mid;
        }
    }
    else {
        n = -n;
        if (n % 2 == 0) {
            const mid = myPow(x, Math.floor(n / 2));
            return 1 / (mid * mid);
        } else {
            const mid = myPow(x, Math.floor((n - 1) / 2));
            return 1 / (x * mid * mid);
        }
    }
};
