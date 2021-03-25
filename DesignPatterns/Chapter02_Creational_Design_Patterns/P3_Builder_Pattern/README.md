# Creational Design Pattern 3: Builder Pattern

## Motivation

Builder Pattern is usually used to create user interface related component. This pattern is mostly used in daily basis.

Why we use Build Pattern ?

1. Because of large number of parameters in constructor, it is hard to follow
2. Large number of getters and setters
3. Telescoping constructors are **not extensible solutions**
    * Telescoping constructors: multiple constructor with different parameters, some are optional, some are mandatory.
    
    If there is 1 parameter added, we need to create 1 telescoping constructor
4. Builder Pattern satisfies the **immutable property**. After an object is constructed, it becomes immutable.
5. Build Pattern does not produce concurrent problems when dealing with multiple threads or processes.
6. Avoid using lots of setters to modify the instance.


## Example

1. Example 1: Construct Person objects in builder pattern

2. Example 2: Contruct Student objects in builder pattern


## Pros and Cons

See above *Why we use Build Pattern?*
