# Behavioral Design Pattern 1: Strategy Pattern (Policy Pattern)

## Motivation

Strategy pattern enables selecting an algorithm **at run-time**.


## Definition

### Principle 1: Encapsulation

Encapsulation separates 2 behaviors of classes from implementation:

1. static code
2. dynamic code: updated frequently

### Principle 2: Program to a supertype

1. the actual run-time object should not be locked into the code. 
2. the type of a variable should be abstract (interface/abstract classes) ———— Dependency Inversion Principle

### Principle 3: Favor composition over inheritance

| Attribute | Inheritance | Composition |
| --------- | ----------- | ----------- |
| Relationship | IS-A     | HAS-A       |
| Definition | a class extends another class | a class has several instance encapsulated variable |
| Problem   | 1. single inheritance in Java <br/> 2. it is static in compile time |  |
| Pros | | Gives more flexibility; Can change behavior at run-time |



## Examples

Example 1: a calculator supports addition, substraction, multiplication, division

Example 2: a calculator support above operations, but implement in another way in `Operationmanager.java` (bad way!!)

Example 3: a renderer showing image on laptop, smartphone and TV


## Pros and Cons

Pros:

1. achieve Open-closed principle and Dependent inversion principle
2. every single possible branch of the application incrases the cyclomatic complexity of the software


## Supplymentary

1. [Cyclomatic complexity](https://en.wikipedia.org/wiki/Cyclomatic_complexity)

2. many if-else statements increases cyclomatic complexity
