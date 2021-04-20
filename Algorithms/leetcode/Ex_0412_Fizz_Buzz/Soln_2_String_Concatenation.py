class Solution_2:
    def fizzBuzz(self, n: int) -> List[str]:
        res = []

        for num in range(1, n+1):
            divisible_by_3 = (num % 3 == 0)
            divisible_by_5 = (num % 5 == 0)

            num_res_str = ''

            if divisible_by_3:
                num_res_str += 'Fizz'
            if divisible_by_5:
                num_res_str += 'Buzz'
            if not num_res_str:
                num_res_str = str(num)
            
            res.append(num_res_str)
        
        return res

# 参考题解：https://leetcode-cn.com/problems/fizz-buzz/solution/fizz-buzz-by-leetcode/

