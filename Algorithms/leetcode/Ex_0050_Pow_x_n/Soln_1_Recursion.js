/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    if (n == 0)
        return 1.0;
    if (n < 0)
        // x ^ (-5) = 1/x * (1/x)^4
        return (1/x) * myPow(1/x, -(n+1));
    const temp = myPow(x, Math.floor(n/2));
    console.log(n, temp);
    return n % 2 == 0 ? temp * temp : x * temp * temp;
};
