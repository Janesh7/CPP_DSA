string -> 1d array of characters
in cin the compiler stops the execution once it encounters:
- space
- tabs
- newline

NUL CHARACTER '\0' is used as terminator, its ASCII value is 0, when compiler finds this char in storage it ends the string retrieving operations
<br />
IMP: Diff btw string and char array : 
std::string stores its data internally in the form of a null terminated C-string, but in normal usage doesnt allow u to access the null terminator.
<br/>
CHECK cplusplus site for all str functions and documentation