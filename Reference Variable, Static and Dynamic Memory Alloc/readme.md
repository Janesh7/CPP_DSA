# Reference Variable
To create a refrence variable 
```
int i = 5;
int& j = i // CREATING A REF VAR
```

- Basically we r creating a reference to the same memory as i, so i++ or j++ would lead to the same result
- ie Same memory different names

Why do we need this?


We know that in cpp, the parameters are passed by values in function, and any updation on it will not reflect outside. Therefore if we want to pass by reference we can pass the REFERENCE VARIABLE in the func. the func should be defined as:
```
int funct(int& n) { return n++;}
```
ie we r creating a ref variable to the same memory instead of creating a new copied value of the parameter.