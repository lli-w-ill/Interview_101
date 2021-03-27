# Multi-threading

## Motivation

1. Programs are sequentially excuted. Time-consuming operations may freeze the application and the users may not know what's happening.
2. Separate multiple tasks which is time critical and might be subject to interference by other tasks.


## Definitions

1. **Process**: an instance of program execution. Each process has its own **register (寄存器)**, **program counter (程序计数器)**, **stack memory** and **heap memory**. A process can have several threads.
    * In Java, we create processes with the help of **ProcessBuilder** class

2. **Thread**: a light-weight process. It is a unit of execution within a given process. Each thread in the process shares the memoyr and resources of the belonging process such as register, stack memory etc metioned above.

3. **Time-slicing**: Processing time for a single core is shared among processes and threads.

Example: 
```
thread #1  ---   ---   ---   ---  --Done

thread #2     ---   ---   ---   --Done
```

4. **Parallel Computing**: Every single processor core has just a single thread so that the thread can run continously. So there is no time-slicing in Parallel Computing.

