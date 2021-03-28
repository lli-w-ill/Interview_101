# Recursion

## Definition

Recursion is a method/procedure where the solution to a problem depends on solutions to smaller instances of the same problem.

## Use cases

* Backtracking
* DFS
* BFS
* Tree problems

## Components

1. Base cases
2. Smaller instances of the same problem

## Types of recursion

### 1. Head Recursion

The recursive call occurs at the beginning of a function.

Head recursion **needs more memory**.

```java
public void head(int N) {
    if (N == 0) 
        return;
    head(N-1);
    System.out.println(N);
}

// head(10)
// 1 2 3 4 5 6 7 8 9 10
```

### 2. Tail Recursion

The recursive call occurs at the end of a function.

Tail recursion can be converted to a loop.

```java
public void tail(int N) {
    if (N == 0) 
        return;
    System.out.println(N);
    tail(N-1);
}

// tail(10)
// 10 9 8 7 6 5 4 3 2 1
```

**Tail recursion avoids StackOverflow errors.** But Python does not support tail recursion optimization. C++ and Java support this.


## Optimization

Modern programming languages transform the tail recursion into an interation. However, Python does **NOT** do such optimization.

Recursive solutions is slower than iterative solutions.

## 