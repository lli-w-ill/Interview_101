# Inter-Thread Communication

## Stack and Heap memory

### Stack Memory

* stores local variables, method arguments, method calls
* fast access

### Heap Memory

* stores objects as long as it is referenced
* slow access

**Every thread has its own stack memory but all threads share the heap memory.**

The main purpose of **synchronization** is the sharing of resources without interference using **mutual exclusion**. That is to say, dealing with shared heap memory.


## Synchronization

### Intrinsic Lock (Monitor Lock)

A thread that needs exclusive and consistent access to an object's fields has to acquire the object's intrinsic lock before accessing them, and then release the intrinsic lock when it is done with them.

The keyword `synchonized` limits that only a single thread can acquire the instinsic lock of the class.

**The problem is that every object has a single monitor lock, if there are 2 independent synchonized methods in a class, then the threads have to wait for each other to release the lock.** --> Slower issue


## Object-level locking

```java
// synchonized on method
public synchronized void increment() {
    counter++;
}

// synchonized on block
public void increment() {
    synchronized(this) {
        counter++;
    }
}

// we get the monitor lock associated with the object itself

```

## Class-level locking

```java
// synchonized on static method
public synchronized void increment() {
    counter++;
}

// synchonized on block associated with a class
public static void increment() {
    synchronized(SomeClass.class) {
        counter++;
    }
}

// we get the monitor lock associated with the class itself

```

## Re-entrant synchronization

Allowing a thread to acquire the same lock more than once is called **re-entrant synchronization**. A thread cannot acquire a lock owned by another thread. In Python, this associates with `RLock` Objects.

Reentrant Lock can prevent **thread starvation**. (Synchronized blocks are unfaire by default). Reentrant lock needs try-catch-finally block, but synchronized blocks don't.


## Inter-Thread communication

Threads that are locking on the same intrinsic/monitor lock can release the lock until the other thread calls `notify()`.

### `wait()` vs. `sleep()`

| # |  wait()  |  sleep()  |
| - | -------- | --------- |
| Can be interrupted ? | Yes | No |
| Must be in a synchronized block ? | Yes | No |
| Release the lock after execution ? | Yes | No |

### `notify()`

notify waiting threads to continue its execution.




## Examples

Example 1: `synchronized` keyword

Example 2: Slower issue

*Two_Independent_Synchonized.java*: because there is a single intrinsic lock associated with a given object or class, 两个 synchronized 方法不能同时由两个 threads 执行

Solution: 

*Object_Level_Lock.java*: use re-entrant synchronization

Example 3: `wait()` and `notify()`

Example 4: Consumer-Producer pattern

Example 5: Re-entrant Lock


## Supplymentary

1. 最好使用 synchonized block, 而不要直接在 method definition 上使用 synchonized. **Rule of thumb: we synchonized blocks that are 100% necessary.**



