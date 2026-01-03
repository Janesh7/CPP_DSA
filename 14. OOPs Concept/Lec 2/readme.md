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


Consider a real-life example of encapsulation, in a company, there are different sections like the accounts section, finance section, sales section, etc. Now,

The finance section handles all the financial transactions and keeps records of all the data related to finance.
Similarly, the sales section handles all the sales-related activities and keeps records of all the sales.
Now there may arise a situation when for some reason an official from the finance section needs all the data about sales in a particular month.


In this case, he is not allowed to directly access the data of the sales section. He will first have to contact some other officer in the sales section and then request him to give the particular data.


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

### Compile time polymorphism - static polym


Two types:
1. **Function Overloading**
2. **Operator Overlaoding**



#### Function overloading

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


#### Operator overloading

We can overload

- Unary operators
- Binary operators
- Special operators ( [ ], (), etc)


Almost all operators can be overloaded except a few. Following is the list of operators that cannot be overloaded. 

- sizeof
- typeid
- Scope resolution (::)
- Class member access operators (.(dot), .* (pointer to member operator))
- Ternary or conditional (?:)


Syntax 

```
return-type operator<op> (params) {}
```
ie return type followeby the operator keyword and then the operator to be overloaded and then the params


**IMP: the first operand is pointed by *this* operator and the other operand is the input argument like in a+b , obj a is pointd by this and b is input srg**

READ DIFF TYPES OF OP OVRLD LIKE for new AND delete where the sytnax/params/return-type is not usual

[More info](https://www.geeksforgeeks.org/operator-overloading-cpp/)

### Runtime polymorphism - Dynamic polym

1. Method/function overriding **DEPENDS UPON INHERITANCE**

- Ex method in parent class which is implemented differently in child class, example function speaking in Animal class which couts smth and then in dog the same method couts bark
- name should be same,
- params should be same
- possible thorugh **INHERITANCE ONLY**

If we have a child class, if it doesnt have its own implementation of a func then base class func is called and if the child has its own implementation then its calls its own func

#### Virtual Function
A virtual function is a member function that is declared in the base class using the keyword virtual and is re-defined (Overridden) in the derived class. 

Some Key Points About Virtual Functions:
- Virtual functions are Dynamic in nature. 
- They are defined by inserting the keyword “virtual” inside a base class and are always declared with a base class and overridden in a child class
- A virtual function is called during Runtime
- Below is the C++ program to demonstrate virtual function:

```cpp
// C++ Program to demonstrate
// the Virtual Function
#include <iostream>
using namespace std;
  
// Declaring a Base class
class GFG_Base {
  
public:
    // virtual function
    virtual void display()
    {
        cout << "Called virtual Base Class function"
             << "\n\n";
    }
  
    void print()
    {
        cout << "Called GFG_Base print function"
             << "\n\n";
    }
};
  
// Declaring a Child Class
class GFG_Child : public GFG_Base {
  
public:
    void display()
    {
        cout << "Called GFG_Child Display Function"
             << "\n\n";
    }
  
    void print()
    {
        cout << "Called GFG_Child print Function"
             << "\n\n";
    }
};
  
// Driver code
int main()
{
    // Create a reference of class GFG_Base
    GFG_Base* base;
  
    GFG_Child child;
  
    base = &child;
  
    // This will call the virtual function 
    base->GFG_Base::display(); // base->display(); gives the same res
  
    // this will call the non-virtual function
    base->print();
}
Output
Called virtual Base Class function

Called GFG_Base print function
```

## Abstraction

**IMPLEMENTATION HIDING**

- Abstractions in class can be achieved through access modifiers

Advantages
- Only u can change it
- security
- increase useablity
- avoid duplication of code


Types of Abstraction:
- Data abstraction – This type only shows the required information about the data and hides the unnecessary data.
- Control Abstraction – This type only shows the required information about the implementation and hides unnecessary information.


Consider a real-life example of a man driving a car. The man only knows that pressing the accelerator will increase the speed of the car or applying brakes will stop the car but he does not know how on pressing the accelerator the speed is actually increasing, he does not know about the inner mechanism of the car or the implementation of the accelerator, brakes, etc in the car. This is what abstraction is.



### Difference btw Abstraction and encapsulation


Encapsulation is the **packing of "data" and "functions operating on that data" into a single component and restricting the access to some of the object's components.**
Encapsulation means that the **internal representation** of an object is generally hidden from view outside of the object's definition.


Abstraction is a mechanism which **represent the essential features without including implementation details.**


Encapsulation:-- Information hiding.
Abstraction:-- Implementation hiding.


Example (in C++):
```
class foo{
    private:
        int a, b;
    public:
        foo(int x=0, int y=0): a(x), b(y) {}

        int add(){    
            return a+b;   
        } 
}  
```

**Internal representation of any object of foo class is hidden outside of this class. --> Encapsulation.**
Any accessible member (data/function) of an object of foo is restricted and can only be accessed by that object only.

```
foo foo_obj(3, 4);
int sum = foo_obj.add();
```
**Implementation of method add is hidden. --> Abstraction.**