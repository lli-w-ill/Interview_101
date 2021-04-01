# Multi-threading

## Motivation

1. Programs are sequentially excuted. Time-consuming operations may freeze the application and the users may not know what's happening.
2. Separate multiple tasks which is time critical and might be subject to interference by other tasks.


## Definitions

1. **Process**: an instance of program execution. Each process has its own **register (寄存器)**, **program counter (程序计数器)**, **stack memory** and **heap memory**. A process can have several threads.
    * In Java, we create processes with the help of **ProcessBuilder** class

2. **Thread**: a light-weight process. It is a unit of execution within a given process. Each thread in the process shares the memoyr and resources of the belonging process such as register, stack memory etc metioned above.

**Difference between processes and threads:**

Threads of the same process run in a shared memory space, while processes run in separate memory spaces.

3. **Time-slicing**: Processing time for a single core is shared among processes and threads.

    * Example: 

```
thread #1  ---   ---   ---   ---  --Done

thread #2     ---   ---   ---   --Done
```

4. **Parallel Computing**: Every single processor core has just a single thread so that the thread can run continously. So there is no time-slicing in Parallel Computing.

![image1](images/image1.png)


## Pros and Cons

Pros:

1. design responsive applications; do several operations concurrently
2. achieve better resource utilization
3. improve performance with multiple cores and parallel computing

Cons:

1. costs in multithreading
2. deal with synchronization sinces threads share the same memory in process
3. easy to make bugs, hard to detect bugs
4. expensive operations (for example, switching between threads)

**Rule of Thumb**: For small problems, it is unnecessary to use multi-threading. For medium and large problems, the curve of running time and number of threads is like an elbow curve.


## Thread States

1. `NEW`: a thread is in NEW state until run `start()` method

2. `RUNNABLE`: after a thread is started, the thread is executing the task and it is in RUNNABLE state

3. `WAITING`: when a thread is waiting, it is in WAITING state. We can call `wait()` or `sleep()` methods to put a thread into this state. After other thread signals, the WAITING thread goes back to RUNNABLE state

4. `DEAD`: after a thread finishes its task

States:

```
    NEW state  ---(call `start()`)--->  RUNNABLE state ---(finish its task)--->  DEAD state
                                            ↑  ↓
                   (other thread's signal)  ↑  ↓  (call `wait()` or `sleep()`)
                                            ↑  ↓
                                        WAITING state
```

## `Volatile` keyword

Every thread in a process has a cache. Reading from cache is way faster than reading from main memory (RAM). 

Every read of a volatile variable will be read from the RAM and not from cache. Do not use *volatile* keyword if not necessary, it prevents instructions re-ordering which is a *performance boost technique*.


## Deadlock and livelock 死锁与活锁

### Deadlock

**Definition:** Deadlock occurs when two or more threads wait forever for a lock or resource held by another of the threads.

Deadlock blocks threads which are waiting for each other **forever**.

### Livelock

**Definition:** Livelock occurs when a thread acts in response to the action of another thread and the other thread's action is also a response to the action of another thread.

Livelock does not block threads but make threads unable to make further progress. It makes threads too busy responding to each other to resume work.

### How to handle deadlock and livelock

How to handle deadlock: 

1. use `Lock` interface's `tryLock()` method (it tries to acquire the lock for a very short amount of time and does not block the thread if the lock is not available.)

2. make threads acquire the lock in the same order to avoid **cyclic dependency** in lock acquisition.

How to handle livelock:

1. make threads retry acquiring the locks at random intervals (add some randomness)


## Atomic Variables

*see reference 3 and example 4*


## Semaphores and Mutexes

### Semaphores

Semaphores are simple variables or abstract data types that are used for controlling access to a common resource. Semaphores is a record of how many units of a particular resource are available. Threads have to wait until a unit of the resource becomes available.

2 types of semaphores:

* Counting Semaphores: allows an arbitrary resource count
* Binary Semaphores: semaphores that are restricted to 0 or 1

Advantages:

* semaphore count may serve as a useful trigger
* producer-consumer problem can be solved and implemented with the help of semaphores

Disadvantages:

* does not keep track of which of the resources are free


### Mutexes (Mutual Exclusion Objects)

Mutural Exclusion is a property of concurrency control which is instituted for the purpose of preventing race conditions.

Mutex is similar to a binary semaphore while binary semaphore can be used as mutex, a mutex is a more specific use-case.

A Lock is designed to enforce a mutual exclusion concurrency control policy.

example:

```java
synchronized(mutex) { ... }
```

|  Semaphores  |  Mutexes  |
| ------------ | --------- |
| a signalling mechanism (e.g. `wait()`, `notify()`) | a locking mechanism |
| allows multiple programs threads to access the **finite** instance of resources | allows multiple program threads to access a **single shared resource** but one at a time |


## Examples

Example 1: incrementor

Example 2: Volatile

Example 3: Deadlock & Livelock, Create threads with lambda expressions

Example 4: Atomic Variables

Example 5: Semaphores

# References

1. [Interface Runnable](https://docs.oracle.com/javase/7/docs/api/java/lang/Runnable.html)

2. [Class Thread](https://docs.oracle.com/javase/7/docs/api/java/lang/Thread.html)

3. [Atomic Variables](https://docs.oracle.com/javase/tutorial/essential/concurrency/atomicvars.html)
