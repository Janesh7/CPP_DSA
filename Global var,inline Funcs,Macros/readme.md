# Macros

- Done using #define

- are like preprocessor directives which add required components to the program before compiling


Example of Macro
- we r using pi alot in our code
- Now we have to change the value, so big task to go change everywhere
- Now we can say that we can create a double var which will store the value, but this will have a minimal performance hit and take memory aswell
- Thats why we use macro


**Macro- Is a peice of code in a program that is replaced by the value of macro**



Logic:


So when we use macro, before compiling the value of PI will be replaced by 3.14 wherever we have used it in the program.




- This is not a varibale hence DOESNT take storage 
- U CANT CHANGE THE VALUE OF IT
- NEED NOT BE TERMINTED BY ;


Example:


```
#include<iostream>
using namespace std;

#define AREA(l,b) (l*)

int main()
{
    int l=10,b=20;
    cout<<AREA(l,b);

}
```
- In this program all the instance of AREA(l,b) is replaced by (l*b) hence this works






Types Of Macros 



Object-like Macros: An object-like macro is a simple identifier that will be replaced by a code fragment. It is called object-like because it looks like an object in code that uses it. It is popularly used to replace a symbolic name with numerical/variable represented as constant.
Below is the illustration of a simple macro:
```
// C++ program to illustrate macros
#include <iostream>
using namespace std;
 
// Macro definition
#define DATE 31
 
// Driver Code
int main()
{
    // Print the message
    cout << "Lockdown will be extended"
         << " upto " << DATE
         << "-MAY-2020";
 
    return 0;
}
Output
Lockdown will be extended upto 31-MAY-2020

```


2. Chain Macros: Macros inside macros are termed as chain macros. In chain macros first of all parent macro is expanded then the child macro is expanded. 
Below is the illustration of a Chain Macro:

```
// C++ program to illustrate macros
#include <iostream>
using namespace std;
 
// Macro definition
#define INSTAGRAM FOLLOWERS
#define FOLLOWERS 138
 
// Driver Code
int main()
{
    // Print the message
    cout << "Geeks for Geeks have "
         << INSTAGRAM << "K followers on Instagram!";
 
    return 0;
}
Output
Geeks for Geeks have 138K followers on Instagram
```
Explanation: 
INSTAGRAM is expanded first to produce FOLLOWERS. Then the expanded macro is expanded to produce the outcome as 138K. This is called the chaining of macros.





   3. Multi-line Macros: An object-like macro could have a multi-line. So to create a multi-line macro you have to use backslash-newline. 
Below is the illustration of multiline macros:
```

// C++ program to illustrate macros
#include <iostream>
using namespace std;
 
// Multi-line Macro definition
#define ELE 1, \
            2, \
            3
 
// Driver Code
int main()
{
    // Array arr[] with elements
    // defined in macros
    int arr[] = { ELE };
 
    // Print elements
    printf("Elements of Array are:\n");
 
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << ' ';
    }
 
    return 0;
}
Output
Elements of Array are:
1  2  3  
```



   4. Function-like Macro: These macros are the same as a function call. It replaces the entire code instead of a function name. Pair of parentheses immediately after the macro name is necessary. If we put a space between the macro name and the parentheses in the macro definition, then the macro will not work. 
A function-like macro is only lengthened if and only if its name appears with a pair of parentheses after it. If we don’t do this, the function pointer will get the address of the real function and lead to a syntax error.
Below is the illustration of function-like macros:

```
// C++ program to illustrate macros
#include <iostream>
using namespace std;
 
// Function-like Macro definition
#define min(a, b) (((a) < (b)) ? (a) : (b))
 
// Driver Code
int main()
{
 
    // Given two number a and b
    int a = 18;
    int b = 76;
 
    cout << "Minimum value between"
         << a << " and " << b
         << " is: " << min(a, b);
 
    return 0;
}
Output
Minimum value between 18 and 76 is 18
Here is one example that will give more understanding of Macros:
```

Problem: We need to find the area of a circle by defining AREA(r) Macros. 

```
#include <iostream>
using namespace std;
#define  PI  3.1416
#define  AREA(r)  (PI*(r)*(r))
 
int main() {
     
      float r = 7;    // radius of circle
       
    cout<<"Area of Circle with radius " << r <<": "<< AREA(r);
   
    return 0;
}
 
    Output
Area of Circle with radius 7: 153.938
```



Questions:
1. What are the advantages and disadvantages of Macros?
Ans. Macros are abbreviations for lengthy and frequently used statements. When a macro is called the entire code is substituted by a single line though the macro definition is of several lines.




The advantage of macro is that it reduces the time taken for control transfer as in case of function.
The disadvantage of it is here the entire code is substituted so the program becomes lengthy if a macro is called several times. 