#include <vector>

using std::vector;

class Tle_1 {
public:
    int countPrimes(int n) {
        // 特判
        if (n <= 2) {
            return 0;
        }

        // 计算 2 ~ 5*10^6 的所有素数
        initPrimes(n);

        return primes.size();
    }

private:
    vector<int> primes;

    void initPrimes(int n) {
        primes.push_back(2);

        for (int i = 3; i < n; i++) {
            bool isPrime = true;
            for (int j = i/2; j >= 2; j--) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                } 
            }
            if (isPrime) {
                primes.push_back(i);
            }
        }
    }
};
