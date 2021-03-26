# Behavioral Design Pattern 5: Template Pattern

## Motivation

There are several operations and procesure in software engineering that are very similar to each other.

For example, for class `Football` and class `Basketball`, they usually have similar methods `startGame`, `goal`, `finishGame`.


## Definition


## Examples

Example 1: Sorting algorithms

Example 2: Football & Basketball matches


## Pros and Cons



## Supplymentary

1. Template Pattern vs. Strategy Pattern

| # |  Template Pattern  |  Strategy Pattern  |
| - | ------------------ | ------------------ |
| 1 | based on inheritance | based on composition |
| 2 | operate on class level (static binding in compile time) | operate on object level (dynamic binding, change behavior at run-time) |

2. Strategy Pattern is usually considered better than Template Pattern, because Strategy Pattern is **dynamic**.
