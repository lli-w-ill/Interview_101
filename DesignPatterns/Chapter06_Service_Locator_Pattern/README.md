# Service Locator Pattern

## Motivation


## Definition

Service Locator Pattern is a design pattern for obtaining processes involved in obtaining a service with a strong abstraction layer.

Service Locator Pattern is an alternative of Dependency Injection. It consists of a central registry "service locator", and we send requests to service locator, and service locator is going to instantiate related object and send back the object.


## Examples


## Pros and Cons

Pros

1. run-time linker: allows code to be added at run-time without re-compiling the source code
2. can make optimization

Cons

1. arder to detect and recovery from errors
2. registry hides the dependencies -> causes run-time errors instead of compile-time errors
3. difficult to maintain the registry (dependency injection is more convenient)


## Supplymentary

1. Compare with Dependency Injection

| # |  Dependency Injection  |  Service Locator Pattern  |
| - | ---------------------- | ------------------------- |
| Same 1 | achieve dependency inversion principle | achieve dependency inversion principle | 
| Diff 1 | no explicit request | explicitly request to "service locator" |
| Diff 2 | easy to test | difficult to test due to black box method |
| Diff 3 | | separate service configuration from the use of services within an application |

2. jndiName: Java Naming and Directory Interface Name

It allows Java's software clients to discover and look at data and objects according to jndiName. It is independent to any implementation.

