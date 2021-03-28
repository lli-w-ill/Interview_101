
def factorial(n: int) -> int:
    if n == 1:
        return 1
    
    # 这个不是尾递归，因为计算 n * factorial(n-1) 之前，需要递归之后的结果
    return n * factorial(n-1)

print(factorial(5))
