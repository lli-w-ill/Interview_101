
def tail(n) -> None:
    if n == 0:
        return
    print(n, end=' ')
    tail(n-1)

def head(n) -> None:
    if n == 0:
        return
    head(n-1)
    print(n, end=' ')

tail(10)
print()

head(10)
print()
