# Creational Design Pattern 4: Prototype Pattern

## Motivation

The aim is to be able to copy existing objects without depending on those given classes.

In most cases, it is hard to copy variables of an objects one by one, because:

1. private variables are not accessible
2. drawback of abstraction (see below)

```java
Animal dog = new Dog();
```

Drawback of abstraction: 如果我们想拷贝一份 dog，首先 `Dog` 类可能有 private 成员；其次，因为 dog 的类型是 Animal interface，所以 dog 可能不能放 Dog 类中的某些**新的成员或方法**

解决方法：

Delegate the object creation problem to the object itself. The operation is called **Cloning**. The `clone` method creates a new instance with all the field values copied.

An object that supports the cloning operation is called a **prototype**. 


## Supplymentary

1. [Interface Cloneable](https://docs.oracle.com/javase/7/docs/api/java/lang/Cloneable.html)

2. Sometimes, we can **eliminate inheritance** with prototype pattern when dealing with complex objects.


