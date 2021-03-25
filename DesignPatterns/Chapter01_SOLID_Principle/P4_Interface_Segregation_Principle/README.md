# (I) Interface Segregation Principle

## Motivation

"Fat interfaces" contains more methods than the actual class needs. If a given interface contains a large amount of abstract method, we need to create multiple interfaces to replace the "fat interface". 我们可以在 *interfaces 之间利用继承关系* 和 *一个 class 实现多个 interfaces*.


## Definition

Software modules (classes and methods) should not be forced to depend upon interfaces that they do not use.

