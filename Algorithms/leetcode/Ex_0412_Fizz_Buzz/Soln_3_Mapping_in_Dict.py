class Solution_3:
    def fizzBuzz(self, n: int) -> List[str]:
        res = []

        # 将映射关系存放在散列表里，这样如果题目要求变更映射关系可以直接在这里添加或修改
        fizz_buzz_dict = {
            3: 'Fizz',
            5: 'Buzz'
        }

        for num in range(1, n+1):
            num_res_str = ''

            for key in fizz_buzz_dict.keys():
                if num % key == 0:
                    num_res_str += fizz_buzz_dict[key]
            
            if not num_res_str:
                num_res_str = str(num)

            res.append(num_res_str)
        
        return res

# 参考题解（推荐）：https://leetcode-cn.com/problems/fizz-buzz/solution/fizz-buzz-by-leetcode/
