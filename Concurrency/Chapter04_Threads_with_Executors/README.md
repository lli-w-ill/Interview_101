# Creating Threads with Executors

Java provides **Executor Framework**. We can manager worker threads efficiently because of **thread pools** with the help of the framework.

Thread pools can reuse threads in an efficient manner by keeping the threadsalive and reusing them.


## 4 Types of executors

1. SingleThreadExecutor

the executor has a single thread and execute processes in a sequential manner. Every task is executed by a new thread.

2. FixedThreadPool(n)

create a thread pool with n threads. Usually n is the number of cores in the CPU. More tasks will be stored in a `LinkedBlockingQueue` data structure.

3. CachedThreadPool

the number of threads is not bounded. 如果需要执行一个新任务时，当前线程池中所有线程都busy，则创建一个新线程并执行该任务；如果一个线程持续60s空闲，则删除该线程。

4. ScheduledExecutor

execute a given operation at regular intervals or we use this eecutor if we wish to delay a certain task.


## Runnable vs. Callable Interfaces

Both run on a different threads than the calling thread, but Callable can return a value and Runnable cannot.

### Runnable

a run-and-forget action. each thread executes `run()` method without a return value

### Callable<T>

each thread executes `call()` method if we want to return a given value

calling thread will be **blocked** till the `call()` method is executed.


## Examples

Example 1: SingleThreadExecutor

Example 2: FixedThreadPools

Example 3: ScheduledExecutor

Example 4: Callable and Future\<\T>


