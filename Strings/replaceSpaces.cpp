
// Replace Spaces



// Problem Statement
// Suggest Edit
// You have been given a string 'STR' of words. You need to replace all the spaces between words with “@40”.
// Detailed explanation ( Input/output format, Notes, Images )

// Constraints:
// 1 <= T <= 50
// 0 <= |STR| <= 100

// Where ‘|STR|’ is the length of a particular string including spaces.

// Time limit: 1 sec
// Sample Input 1:
// 2
// Coding Ninjas Is A Coding Platform
// Hello World
// Sample Output 1:
// Coding@40Ninjas@40Is@40A@40Coding@40Platform
// Hello@40World
// Explanation Of Sample Output 1:
// In test case 1, After replacing the spaces with “@40” string is: 

// Coding@40Ninjas@40Is@40A@40Coding@40Platform

// In test case 2, After replacing the spaces with “@40” string is: 

// Hello@40World
// Sample Input 2:
// 3
// Hello
// I love coding
// Coding Ninjas India
// Sample Output 2:
// Hello
// I@40love@40coding
// Coding@40Ninjas@40India    
// Explanation For Sample Output 2:
// In test case 1, After replacing the spaces with “@40” string is: 

// Hello

// In test case 2, After replacing the spaces with “@40” string is: 

// I@40love@40coding

// In test case 3, After replacing the spaces with “@40” string is: 

// Coding@40Ninjas@40India

#include<string>
#include<iostream>
using namespace std;
string replaceSpaces(string &str){
	string temp = "";
    
    for(int i=0; i<str.length(); i++) {
        if(str[i] == ' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else
        {
            temp.push_back(str[i]);
        }
    }
    return temp;
}