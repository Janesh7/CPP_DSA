// 2299. Strong Password Checker II


// A password is said to be strong if it satisfies all the following criteria:

// It has at least 8 characters.
// It contains at least one lowercase letter.
// It contains at least one uppercase letter.
// It contains at least one digit.
// It contains at least one special character. The special characters are the characters in the following string: "!@#$%^&*()-+".
// It does not contain 2 of the same character in adjacent positions (i.e., "aab" violates this condition, but "aba" does not).
// Given a string password, return true if it is a strong password. Otherwise, return false.

 

// Example 1:

// Input: password = "IloveLe3tcode!"
// Output: true
// Explanation: The password meets all the requirements. Therefore, we return true.
// Example 2:

// Input: password = "Me+You--IsMyDream"
// Output: false
// Explanation: The password does not contain a digit and also contains 2 of the same character in adjacent positions. Therefore, we return false.
// Example 3:

// Input: password = "1aB!"
// Output: false
// Explanation: The password does not meet the length requirement. Therefore, we return false.
 

// Constraints:

// 1 <= password.length <= 100
// password consists of letters, digits, and special characters: "!@#$%^&*()-+".


class Solution {
public:
    bool strongPasswordCheckerII(string str) 
	{
        if (str.length()<8)
            return false;
        int count=0;
        int lower=0;
        int upper=0;
        int digit=0;
        int sp_char=0;
        
        int idx=0;
        while(idx < str.length())
        {
        	if(str[idx]>='a' and str[idx]<='z')
        	lower++;
        	else if(str[idx]>='A' and str[idx]<='Z')
        	upper++;
        	else if(str[idx]>='0' and str[idx]<='9')
        	digit++;
        	else 
        	sp_char++;
        	
        	if((idx)<str.length() and (idx+1)<str.length())
        	{
        		if(str[idx] == str[idx+1])
        		{
        		   return false;	
				}
			}
			
			count++;
			idx++;
		}
        if (lower && upper && digit && sp_char)
            return true;
        return false;

    }
};


// Copied code 


// In the given code, the type casting to `int` is performed to convert each character of the `password` string into its corresponding ASCII value. This is done by assigning the ASCII value of the character to the integer variable `x`.

// The purpose of converting characters to their ASCII values is to perform comparisons with specific ASCII values. For example, `(int)'a'` represents the ASCII value of lowercase 'a', `(int)'A'` represents the ASCII value of uppercase 'A', and so on.

// In this code, the ASCII values are used to check if a character falls within a certain range. For instance, `(x >= (int)'a' && x <= (int)'z')` is used to determine if the character is a lowercase letter, `(x >= (int)'A' && x <= (int)'Z')` checks for uppercase letters, and `(x >= (int)'0' && x <= (int)'9')` checks for digits.

// Regarding the question of speed, type casting characters to integers in this context does not provide a significant speed advantage. It primarily serves the purpose of performing ASCII value comparisons. In most cases, modern compilers optimize these operations, and the performance impact is negligible.

// It's worth noting that readability and code clarity are important factors to consider. If the code intends to check for lowercase, uppercase, or digit characters, it would be more readable to use the character literals directly instead of their ASCII values. For example, `('a' <= password[i] && password[i] <= 'z')` instead of `(x >= (int)'a' && x <= (int)'z')`. Using character literals can improve code understanding and maintainability.


class Solution {
public:
    bool strongPasswordCheckerII(string password) 
    {
        if(password.size() < 8) return false;

        int lower = 0, upper = 0, digit = 0, special = 0, two = 0;
       

        

        for(int i = 0 ; i < password.size() ; i++)
        {
            int x = (int)password[i];

            if(x >=  (int)'a' && x <= (int)'z') lower = 1;
            if(x >=  (int)'A' && x <= (int)'Z') upper = 1;
            if(x >=  (int)'0' && x <= (int)'9') digit = 1;
           

            if(i>0)
            {
                if((int)password[i-1] == (int)password[i]) return false;
            }

        }

        string spec = "!@#$%^&*()-+";
        for(int i = 0 ; i < password.size() ; i++)
        {
            int x = (int)password[i];
            
            for(int j = 0 ; j < spec.size() ; j++)
                if(x == (int)spec[j])
                {    
                    special = 1;                
                    break;
                }
        }

        if((lower + upper + digit + special)  == 4) return true;

        cout << (int)'@' << " " << (int)'!' << " "<< (int)'+';
        return false;    
    }
};