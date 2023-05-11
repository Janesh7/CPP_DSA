# OOPs Concept

- Its a type of programming technique/paradigm/style where the programming style revolves around object
- Object is a real world entity which has state/property and behaviour
- **Helps with readabilty, extensiblity, managebility**
- User defined datatype - class - its a template
- Object is an instance of class




Some IMP points to remember

- When we create a class the memory assigned to it will be the sum of all the memories of its properties **AND PADDING (GREEDY ALLIGNMENT)**.
- **If the class is empty class , the memory assigned to it will be 1 byte, which is used for identification**
- to include a file - 
```
#include "hero.cpp"
```
- to access the data member/propery (it should be public) we use dot operator '.' 
- getter used for returning the value/ reading
- setter used to modify the value, certain conditions can be used

# Padding and allignment

We know that a struct size is not only the summation of all the data members, rather it's the minimum sum guaranteed. **The compiler adds some padding for data member alignment.**


In the C++ class, things are exactly the same as a struct. But there are a few more things.


Firstly, while in C++ there are member functions, static data members. Do those have any contribution to the size of the class, objects?


**The answer is no. Only the non-static data members contribute to the size** of class and objects. This is because static members have only one instance which is shared among all objects. And normal member functions are like executable code which does not have size like data members.

Like in the following class,

```
class A {
private:
    static int i;
    int a;
    char b;

public:
    A()
    {
        a = 0;
        b = '#';
    }
    A(int aa, char bb)
    {
        a = aa;
        b = bb;
    }
    int get_int()
    {
        cout << a << endl;
        return a;
    }
    char get_char()
    {
        cout << b << endl;
        return b;
    }
};
```
Size of the class should be sum of all the non-static data member+ padding, which is like below:

![App Screenshot](https://www.includehelp.com/cpp-tutorial/Images/size-of-a-class-1.jpg)

Above is the alignment of class A and that's why the size of the class is 8 Bytes. **Static data members and member functions have no contribution.**


# How compiler adds padding?

Now the question is how compiler adds padding and align? The method is compiler dependent and kind of greedy. **It aligns till the boundary of maximum memory allocated.**

Here we find that max memory allocated is 8 Bytes, thus all the data members acquire 8 Bytes and the total size is 32 Bytes. Now the question is will it happen every time similarly?



- Is it like the number of data members * max datatype size?


The answer is no. **It will try to align optimally keeping the same order.** Check the example next

# Size of a derived class


**What is the size of a derived class? Of course, a derived class has all data members of the base class it inherits and does it has its own copied of those data members too. Thus size should be the size of base class data members + size of derived class data members.**

Let's check the below code and the output.

In the above structure, we find that the size is 24 Bytes though the same data members have been used. This is due to the change in the order of the member declaration. In this case, the alignment and padding would be like below:


```
#include <bits/stdc++.h>
using namespace std;

class Base {
protected:
    static int i;
    int a;
    char b;

public:
    Base()
    {
        a = 0;
        b = '#';
    }
    Base(int aa, char bb)
    {
        a = aa;
        b = bb;
    }
    int get_int()
    {
        cout << a << endl;
        return a;
    }
    char get_char()
    {
        cout << b << endl;
        return b;
    }
};

class Derived : public Base {

private:
    int c;
    char d;

public:
    Derived()
    {
        c = 0;
        d = '#';
    }
    Derived(int cc, char dd)
    {
        c = cc;
        d = dd;
    }
    int get_int()
    {
        cout << c << endl;
        return c;
    }
    char get_char()
    {
        cout << d << endl;
        return d;
    }
};

int main()
{
    Base b;
    Derived d;
    printf("Size of class Base: %lu\n", sizeof(Base));
    printf("Size of object b: %lu\n", sizeof(b));
    printf("Size of class Derived: %lu\n", sizeof(Derived));
    printf("Size of object d: %lu\n", sizeof(d));
    return 0;
}
Output:

Size of class Base: 8
Size of object b: 8
Size of class Derived: 16
Size of object d: 16
```


So here the size of the base class object is 8 bytes, whereas the size of the derived class object is 16 Bytes.

For the base class it's similar like below:

![App Screenshot](https://www.includehelp.com/cpp-tutorial/Images/size-of-a-class-2.jpg)


While for the derived class it's like:


![App Screenshot](https://www.includehelp.com/cpp-tutorial/Images/size-of-a-class-3.jpg)



**So the thing is the order of data members are being maintained. And since we know that the base class constructor is invoked first, that's why the base class members come first.**

Now let's change the order of data member in the derived class and check the size of the class & object.

```
#include <bits/stdc++.h>
using namespace std;

class Base {
protected:
    static int i;
    int a;
    char b;

public:
    Base()
    {
        a = 0;
        b = '#';
    }
    Base(int aa, char bb)
    {
        a = aa;
        b = bb;
    }
    int get_int()
    {
        cout << a << endl;
        return a;
    }
    char get_char()
    {
        cout << b << endl;
        return b;
    }
};

class Derived : public Base {

private:
    char d;
    int c;

public:
    Derived()
    {
        c = 0;
        d = '#';
    }
    Derived(int cc, char dd)
    {
        c = cc;
        d = dd;
    }
    int get_int()
    {
        cout << c << endl;
        return c;
    }
    char get_char()
    {
        cout << d << endl;
        return d;
    }
};

int main()
{
    Base b;
    Derived d;
    printf("Size of class Base: %lu\n", sizeof(Base));
    printf("Size of object b: %lu\n", sizeof(b));
    printf("Size of class Derived: %lu\n", sizeof(Derived));
    printf("Size of object d: %lu\n", sizeof(d));
    return 0;
}
Output:

Size of class Base: 8
Size of object b: 8
Size of class Derived: 12
Size of object d: 12
```


Just changing the order of member we found that derived class is having size 12 Bytes now. So there must be some better alignment now.

**So, as we can think of compiler went for greedy alignment and now it's able to align optimally (Remember compiler can’t change the order of data member).**

![App Screenshot](https://www.includehelp.com/cpp-tutorial/Images/size-of-a-class-4.jpg)
Above is the alignment for the Derived class and now the size is 12 Bytes, instead of 16 because of the above alignment. We saw that compiler keeps aligning greedily & that's why it aligned char b of base class member & char d, which is its member, in the same row. When it tried to align int c, it could not as only 2 bytes were left. But instead of int, if it was char only then it would have aligned in the same line.


# The virtual keyword and its effect on size

We know in the derived class it can inherit the base class as virtual too. What would be the size of the derived class in that case? Will there be any changes?

The answer is yes. **There will be an additional 8 bytes which is nothing but the size of VTPR (Virtual Table pointer)**


So, for the first derived class example, we got 16 Bytes, but here we have added the virtual keyword and got size 24 Bytes which is due to the size of VTPR.

```
#include <bits/stdc++.h>
using namespace std;

class Base {
protected:
    static int i;
    int a;
    char b;

public:
    Base()
    {
        a = 0;
        b = '#';
    }
    Base(int aa, char bb)
    {
        a = aa;
        b = bb;
    }
    int get_int()
    {
        cout << a << endl;
        return a;
    }
    char get_char()
    {
        cout << b << endl;
        return b;
    }
};

class Derived : virtual public Base {

private:
    char d;
    int c;

public:
    Derived()
    {
        c = 0;
        d = '#';
    }
    Derived(int cc, char dd)
    {
        c = cc;
        d = dd;
    }
    int get_int()
    {
        cout << c << endl;
        return c;
    }
    char get_char()
    {
        cout << d << endl;
        return d;
    }
};

int main()
{
    Base b;
    Derived d;
    printf("Size of class Base: %lu\n", sizeof(Base));
    printf("Size of object b: %lu\n", sizeof(b));
    printf("Size of class Derived: %lu\n", sizeof(Derived));
    printf("Size of object d: %lu\n", sizeof(d));
    return 0;
}
Output:

Size of class Base: 8
Size of object b: 8
Size of class Derived: 24
Size of object d: 24
```

So, here we got the idea of a normal class and object size. We learnt how the compiler aligns the data members and add padding. Also, we extended the discussion to the size of the derived class.

To end the discussion let me just throw a brain teaser. What do you think would be the size of an empty class?

Do you think it's 0?

```
#include <bits/stdc++.h>
using namespace std;

class A {
};

int main()
{
    printf("Size of class A: %lu\n", sizeof(A));
    return 0;
}
Output:

Size of class A: 1
```

Well, the size of the empty class is not 0. **This is actually to ensure that two different objects will have different addresses.**


-----------------------------------------------------



# Dynamic Allocaton

Refresher: to create int dynamiclly
```
int *i = new int;
//also
char *name;
name = new char[100];
```
- pointer points to 4 bytes in heap(dynamic memory)


For object:
```
Hero *h = new Hero;
```
- Creates a Hero type pointer which points to 8 bytes (as seen in example) in Heap memory which was allocated for it



Now to use the object:

```
Hero *b = new Hero;
b->setLevel('A');
b->setHealth(70);
cout << "level is  " << (*b).level << endl;
cout << " health is " << (*b).getHealth() << endl;

// OR
cout << "level is  " << b->level << endl;
cout << " health is " << b->getHealth() << endl;
```





----------------------------------------

- whenever we create an obj a constructor is called
- It invokes at object creation
- No i/p parameter


ie Whenever we do Hero ramesh it is done as ramesh.Hero()
- It is same whether called statically or dynamically


# This keyword


for example 

```
class smth {
    int x;
    smth(int x) {
        x = x;
    }
}
```

As we can see the name of the variable is same (x). if we dont use this, only the local scoped variable is used and the value doesnt get set. Hence we use this keyword to differentaite the variables. Ex this->x = x;


- **this keyword stores the address of the current object**
- this is a pointer which points to the current object.
- we will call the function from an  object and its addy is used for *this* keyword.
- if u print the this keyword and address of the object called it will give the same addy.
Use this code for verification
```
...
// In constructor
cout<<"this "<<this;


// In main function
cout<<&ramesh;

```


- **If we made a(any number) paramterized constructors, then the default constructor by the compile will not be there. so if u try to create a obj without a parameter it gives error.**

- **Copy constructor is always generated**

use Obj o1(o2);

- we can make our own copy constructor


- **IMP: When we write our own copy constructor, we MUST use & to PASS BY REFERENCE. This is important as without it, the object will be passed as pass by value, ie it will create a copy of the same (and we r declaring the copy constructor there), hence recursively they will be calling each other infinetly(loop)**



copy constr -> create temp(as the object is copied in pass by value) -> calls copy constructor to copy the value ... infinite


- **Default copy constructor is SHALLOW COPY**


Setter for strings 
```
void setName(char name[])
{
    strcpy(this->name, name);
}
```

- If we use default constructor, it makes a shallow copy, it works, but if we change the attr (any array, string of anything which is passed by value) of object 1 , the attr of other object also gets change, hence copy constr is required.




- **Wkt that array, (array of char in the example taken), the parameter is taken as a pointer. so when we copy the object we copy this pointer address. Now both stores the same address as the pointer and changing any would result in a change in both the values. Rest values like int n all r copied and since that is not a address it works fine** 



Therefore always deep copy maually by using own copy constr using **strcpy**

```
Hero(Hero &temp)
{

    char *ch = new char[strlen(temp.name) + 1];
    strcpy(ch, temp.name);
    this->name = ch;

    cout << "Copy constructor called" << endl;
    this->health = temp.health;
    this->level = temp.level;
}
```


**Copy assignment operator '='**
let two object a, b be alr created, then a=b; would do a.x1 = b.x1 , a.x2 = b.x2 and so on


# Destructor

- memory deallocation
- called before destroyin an object
- no return type like constructor and no params as well
- ~ is used before the class name -> desctructor
- **IMP : whichever object is statically created, the destructor is called automatically, but for DYNAMICALLY ALLOCATED OBJECTS, IT SHOULD be called MANUALLY ie delete obj;**



# Const keyword

NOTE:

"int x{10};" (**uniform initialization**): This syntax uses curly braces ({}) for initialization and is part of the uniform initialization introduced in C++11. It provides a consistent initialization mechanism for different types. It enforces stricter type checking and prevents narrowing conversions. For example, if you try to initialize a floating-point variable using "int x{10.5};", it will result in a compilation error. Uniform initialization also allows you to initialize aggregates (e.g., arrays or structs) using the same syntax.


**Const keyword**



1. **`const` in Pointers:**
   - `const` can be used to declare a pointer to a constant object. For example:
   
     ```cpp
     const int* ptr;
     ```
   
     This means that `ptr` is a pointer to an integer that is treated as constant. It allows you to read the value pointed to by `ptr`, but you cannot modify that value through `ptr`. However, you can make `ptr` point to a different address.
   
   - To create a constant pointer (where the pointer itself cannot be modified to point to a different address), you can use:
   
     ```cpp
     int* const ptr;
     ```
   
     Here, `ptr` is a constant pointer to an integer. It means that `ptr` always points to the same address, but you can modify the value at that address.
   
   - Additionally, you can combine both forms to create a constant pointer to a constant object:
   
     ```cpp
     const int* const ptr;
     ```
   
     This creates a constant pointer to a constant integer, where both the pointer and the value it points to are treated as constant.
   
2. **`const` in Objects:**
   - When `const` is used with an object, it indicates that the **object itself is treated as constant**, and its member variables cannot be modified.
   
     ```cpp
     class MyClass {
     public:
         void doSomething() const;
     };
     ```
   
     In this example, the member function `doSomething()` is declared as `const`. It means that this function is not allowed to modify the member variables of the object it is called on (unless they are explicitly marked as `mutable`).
   
3. **`const` Functions, Parameters, and Return Types:**
   - When `const` is used with a function, it indicates that the function **does not modify the state of the object** it is called on.
   
     ```cpp
     class MyClass {
     public:
         int getValue() const;
     };
     ```
   
     In this case, the member function `getValue()` is declared as `const`, indicating that it does not modify the internal state of the object and is safe to call on constant objects.
   
   - `const` can also be used with function parameters. When a parameter is declared as `const`, it means that the function guarantees not to modify the value of that parameter.
   
     ```cpp
     void printValue(const int x);
     ```
   
     Here, `printValue` takes a constant integer as a parameter, ensuring that the function does not modify the value of `x`.
   
   - Similarly, `const` can be used as a return type to indicate that the **function returns a constant value that should not be modified.**
   
     ```cpp
     const int getConstantValue();
     ```
   
     This function **returns a constant integer value that should not be modified by the caller.**

4. Here, ptr is a pointer to a constant integer. It means that the value pointed to by ptr cannot be modified through ptr, but ptr itself can point to a different address.

Similarly, you can create a constant reference using the const keyword:

```cpp
const int& ref = x;
```

In this case, ref is a constant reference to x, and you cannot modify the value of x through ref.




Using `const` in these various contexts helps enforce immutability, prevents accidental modifications, and allows the compiler to optimize code based on the constness of objects, parameters, and return types.



[More info](https://www.geeksforgeeks.org/const-keyword-in-cpp/)



1. When the pointer variable point to a const value:

```
const int* i = &x;
const char* j = &y;

// Value of x and y can be altered,
// they are not constant variables
x = 9;
y = 'A';
```

Here in the above case, i and j are two pointer variables that are pointing to a memory location const int-type and char-type, but the value stored at these corresponding locations can be changed as we have done above.

2. When the const pointer variable point to the value:

```
// x,z are int and other chars
int* const i = &x;
 
// const pointer(j) pointing
// to the var y's location
char* const j = &y;


// The values that is stored at the memory location can modified
// even if we modify it through the pointer itself
// No CTE error
*i = 10;
*j = 'D';

// CTE because pointer variable
// is const type so the address
// pointed by the pointer variables
// can't be changed
// i = &z;
// j = &p;
```

3. When const pointer pointing to a const variable:

```
int x{ 9 };
 
const int* const i = &x;

// *i=10;  
// The above statement will give CTE
// Once Ptr(*i) value is
// assigned, later it can't
// be modified(Error)
```





**Pass const-argument value to a non-const parameter of a function cause error: Passing const argument value to a non-const parameter of a function isn’t valid it gives you a compile-time error.**


In nutshell, the above discussion can be concluded as follows:

1. int value = 5;         // non-const value

2. const int *ptr_1 = &value;      // ptr_1 points to a “const int” value, so this is a pointer to a const value.

3. int *const ptr_2 = &value;        // ptr_2 points to an “int”, so this is a const pointer to a non-const value.

4. const int *const ptr_3 = &value;   // ptr_3 points to a “const int” value, so this is a const pointer to a const value.


# Initialization List

In C++, an initialization list is a syntax construct used in the constructor of a class to initialize member variables. It allows you to initialize member variables directly when they are created, before the body of the constructor executes. The initialization list is placed after the constructor's parameter list, separated by a colon ":".

Here's an example to illustrate its usage:

```cpp
class MyClass {
private:
    int x;
    double y;
public:
    MyClass(int a, double b) : x(a), y(b) {
        // Constructor body
    }
};
```

In the above code, `x` and `y` are initialized using the initialization list. The syntax `x(a)` initializes the member variable `x` with the value of the constructor parameter `a`, and `y(b)` initializes `y` with the value of `b`.

Initialization lists offer several advantages:

1. Efficiency: Initialization lists can be more efficient than assigning values to member variables within the constructor body. When you assign values in the constructor body, the member variables are first default-constructed, and then their values are reassigned. With initialization lists, the member variables are constructed directly with the specified values.

2. Const member variables: If you have `const` member variables or references in your class, you must use the initialization list to assign them a value, as they cannot be assigned after they are constructed.

3. Initialization of base classes: If your class inherits from a base class, you can use the initialization list to initialize the base class's constructor.

4. Initialization of member objects: If your class has member objects that require initialization, you can use the initialization list to specify their initial values.

**Why cosnt and reference variable requires initialization list**

Const variables and reference variables require initialization lists because they have specific initialization requirements that cannot be fulfilled within the constructor body.

1. Const variables: Const variables must be initialized at the point of their creation and cannot be reassigned later. Since the constructor body is executed after the member variables are default-constructed, you cannot assign a value to a const variable within the constructor body. Therefore, initialization lists provide a way to directly initialize const variables when the object is constructed.

2. Reference variables: Reference variables must be bound to an object when they are created and cannot be re-bound later. Similar to const variables, you cannot assign a value to a reference variable within the constructor body because it would be too late. The initialization list allows you to initialize reference variables with the desired object immediately upon construction.

--------

- **For initialization of member objects which do not have default constructor:** 
In the following example, an object “a” of class “A” is data member of class “B”, and “A” doesn’t have default constructor. Initializer List must be used to initialize “a”.


```
#include <iostream>
using namespace std;
 
class A {
    int i;
public:
    A(int );
};
 
A::A(int arg) {
    i = arg;
    cout << "A's Constructor called: Value of i: " << i << endl;
}
 
// Class B contains object of A
class B {
    A a;
public:
    B(int );
};
 
B::B(int x):a(x) {  //Initializer list must be used
    cout << "B's Constructor called";
}
 
int main() {
    B obj(10);
    return 0;
```

Similarly base class var can be set 


- **When constructor’s parameter name is same as data member** 
If constructor’s parameter name is same as data member name then the data member must be initialized either using this pointer or Initializer List. In the following example, both member name and parameter name for A() is “i”.

- **For Performance reasons:** 
It is better to initialize all class variables in Initializer List instead of assigning values inside body. Consider the following example: 

```
// Without Initializer List
class MyClass {
    Type variable;
public:
    MyClass(Type a) {  // Assume that Type is an already
                     // declared class and it has appropriate
                     // constructors and operators
      variable = a;
    }
};
```

Here compiler follows following steps to create an object of type MyClass 
1. Type’s constructor is called first for “a”. 

2. Default construct “variable”
3. The assignment operator of “Type” is called inside body of MyClass() constructor to assign 

    variable = a;
4. And then finally destructor of “Type” is called for “a” since it goes out of scope.



Now consider the same code with MyClass() constructor with Initializer List 

```
// With Initializer List
class MyClass {
    Type variable;
public:
    MyClass(Type a):variable(a) {   // Assume that Type is an already
                     // declared class and it has appropriate
                     // constructors and operators
    }
};
```

With the Initializer List, the following steps are followed by compiler: 
1. Type’s constructor is called first for “a”. 

2. Parameterized constructor of “Type” class is called to initialize: variable(a). The arguments in the initializer list are used to copy construct “variable” directly. 
3. The destructor of “Type” is called for “a” since it goes out of scope.
As we can see from this example if we use assignment inside constructor body there are three function calls: constructor + destructor + one addition assignment operator call. And if we use Initializer List there are only two function calls: copy constructor + destructor call.

# Static keyword

- BELONGS TO CLASS
- NO NEED TO CREATE AN OBJECT TO ACCESS IT.
- static keyword
- To initialize an static member without an obj

```
datatype class_name::data_member_name = value;
int Hero::TimeToComplete = 1;
// access
cout<<Hero::TimeToComplete;
```
- U can use an object to call the static member like a.TimeToComplete but ITS NOT RECOMMENDED TO do this as it doesnt belong to an object but belongs to a class.


**Static functions**

- Doesnt need an object to use the function rather use class
- static functions doesnt have *this keyword* as this is a pointer to current object.
- STATIC FUNCTIONS CAN ACCESS ONLY THE STATIC MEMBERS
- **Therefore it cant access the noraml data members of the class**