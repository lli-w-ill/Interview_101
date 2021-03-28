
def factorial(n: int, res: int) -> int:

    if n == 1:
        return res
    
    # 这个是尾递归，因为不需要在内置栈保存当前 function call
    return factorial(n-1, n*res)

print(factorial(5, 1))