# Concurrent Collections

## 1. Countdown Latch

Countdown latches is used to synchronize one or more tasks by forcing them to wait for the completion of a set of operations being performed by other tasks.

**a CountDownLatch cannot be reset**. If it is necessary to use reset, use **CyclicBarrier**.


## 2. Cyclic Barrier

Cyclic Barrier is used in situations when we want to create a group of tasks to perform work in parallel to wait until they are all finished before moving on to the next step.


## 3. Blocking Queue

Blocking Queue is an interface that represents a synchronized and thread-safe queue. It handles low-level synchronization for us.


## 4. Delay Queue

Delay Queue is an unbounded BlockingQueue of objects that implement the Delayed interface.


## 5. Priority Blocking Queue


## 6. Concurrent Hash Map


## 7. Exchanger

Exchanger is used to exchange variables among threads.



## Examples

Example 1: Countdown Latch

Example 2: Cyclic Barrier

Example 3: Blocking Queue

Example 4: Delay Queue

Example 5: Priority Blocking Queue

Example 6: Concurrent Hash Map

Example 7: Exchanger

