# Imp OOPs concept 4 pillars of OOPs - Inheritance, Polymorphism, Encapsulation, & Abstraction

## Encapsulation

- **Wrapping up data members and functions**

- **Fully encapsulated class** - all data members are private.
- not to be confused with abstraction. Encapsulation is **INFORMATION/DATA HIDING**. whereas **ABSTRACTION -> IMPLEMENTATION HIDING**


Advantages/ Application
- Data hiding, increase security
- if we wan, we can make the class read only (no setters, only getter)
- Code reuse
- **Unit testing**


## Inheritance

- class which inherits is subclass/child/derived class. And the class which is used to inherit is called parent class/super/base class

How to use (Dont forget **colon and Access modifier**)
```
class child_class: access_modifier parent_class, am p_class2, ... {}
```


![App Screenshot](https://i.stack.imgur.com/kmBSm.jpg)


Types of inheritance

![App Screenshot](https://1.bp.blogspot.com/-R7YI4glgS78/X37SW9YAYMI/AAAAAAAAle0/S2UiLNqeYfwuc0lnk2WdnMqUSxMuRnFwACLcBGAsYHQ/s471/different-types-of-inheritance.png) 


**Hierarchical Inheritance: one class serve as parent for more than 1 class**


- INHERITANCE AMBIGUITY

Imagine a multiple inheritance where class C inherits from clas A, B. If class A, B have same named function with same arguments then compiler doesnt know which to execute , hence use scope resolution operator (::)


**Syntax**
```
C obj;
obj.A::func();
obj.B::func();
```


## Polymorphism

VV IMP - asked everywhere

- many forms

### Compile time polymorphism


Two types:
1. **Function Overloading**
2. **Operator Overlaoding**



**Function overloading**

- Function signature should be changed in order to achieve this
- **Changing the return type doesnt overload a function anmd would give error**
- Input arguments should change in order to achieve this, u can change
    1. number of args
    2. type of arg
    3. Different sequence of params

- It can also be achieved by default arguments (NOT THAT IT WOULD MAKE 2 func different), but the fact that u can change the number of parameter while using it, 


**How does Function Overloading work?**

- Exact match:- (Function name and Parameter)

- If a not exact match is found:–
               ->Char, Unsigned char, and short are promoted to an int.

               ->Float is promoted to double

- If no match is found:
               ->C++ tries to find a match through the standard conversion.

- ELSE ERROR 🙁