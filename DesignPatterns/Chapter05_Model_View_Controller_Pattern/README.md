# Model-View-Controller (MVC) Pattern

MVC Pattern is used for desktop application with user interface components. It is also popular for web applciations.


## Component 1: Model

Model include all the data and data-related logic.

* Data access object (DAO)
* Model classes
* Databases


## Component 2: View

View handles user interactions (GUI) and presents the data to the user

* User interface components
* Buttons
* Text field


## Component 3: Controller

Controller is an abstract layer between View and Model. It handles communications between Model and user interface components.


## Pros and Cons

Pros:

1. easy to test
2. achieve loosely coupled software design
3. separation of logic

Cons:

1. when the model changes frequently, views have to be changed as well, vice versa
2. the view takes time to render

Solutions:

1. use MVVM architecthre (Model-View-View-Model), binds view components with view components, this is used in AngularJS
