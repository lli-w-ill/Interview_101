# Threads Manipulation

## Construct Thread

### Way 1: Implement Runnable interface

see *Example2_implement_Runnable.java*

### Way 2: Anonymous Runnable

see *Example2_anonymous_Runnable.java*

### Way 3: Extends Thread class

see *Example2_extends_Thread.java*

Usually Way 1 and Way 2 are preferred. Because:

    * Reason 1: The class which extends Thread cannot extends other class
    * Reason 2: Interfaces allows multi-inheritance
    * Reason 3: Implement Runnable does no harm in the software logic


## Daemon Threads and Worker Threads

When we start a program, a main thread is started at the beginning. We can create child threads from the main thread. The main thread is the last thread to finish execution.

### Daemon Threads

Daemon threads are intended as helper threads. They are low-priority threads that runs in background to perform tasks such as garbage collection.

Usually daemon threads for **I/O operations or services**.

Daemon threads are terminated by the **JVM** when **all other worker threads are terminated**.

We need to use `setDaemon(true)` to set a worker thread to be daemon thread.


### Worker Threads

Worker threads are not terminated while daemon threads are interrupted by the JVM.

When we create a thread, it is a worker thread by default.


## Examples

Example 1: 3 ways to instantiate a thread

Example 2: join method

Example 3: Daemon Threads and Worker Threads


# References

1. [Interface Runnable](https://docs.oracle.com/javase/7/docs/api/java/lang/Runnable.html)

2. [Class Thread](https://docs.oracle.com/javase/7/docs/api/java/lang/Thread.html)
