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
- This saves the memory as in pass by value a new memory is used
- We can use REFERENCE VARIABLE as a return type also:
```
int& update(int n)
{
    int a = 10;
    int& ans = a;
    return ans;
}
```


NOTE: THIS IS A VERY BAD PRACTISE AS U CAN SEE WE HAVE CREATED A LOCAL VARIABLE a AND WE ARE RETURNING ITS REF, WKT THE VARIBLE A'S MEMORY WOULD BE DELETED ONCE THE FUNCTION IS FULLY EXECUTED