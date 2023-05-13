// 13. Roman to Integer
// Easy


// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.


// Approach: If a smaller number appears before a larger number, it indicates that the number is smaller by a quantity used as a suffix to it, which made going backwards seem easy.


// Using hashmap

int romanToInt(string s) 
{
    unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
   // Put the last chars value                             
   int sum = T[s.back()];
   
   // Go till size -2 coz we r using (i+1) in our logic, if we take usual size-1 it will overflow.
   for (int i = s.length() - 2; i >= 0; --i) 
   {
       if (T[s[i]] < T[s[i + 1]])
       {
           sum -= T[s[i]];
       }
       else
       {
           sum += T[s[i]];
       }
   }
   
   return sum;
}


// Using switch

class Solution
{
public:
    int DecimalNumericalPlace(char roman_np_value)
    {
        switch (roman_np_value)
        {
        case 'M':
            return 1000;
            break;

        case 'D':
            return 500;
            break;

        case 'C':
            return 100;
            break;

        case 'L':
            return 50;
            break;

        case 'X':
            return 10;
            break;

        case 'V':
            return 5;
            break;

        case 'I':
            return 1;
            break;
        default:
            return -1;
        }
    }

    int romanToInt(string s)
    {
        int len = s.size();
        int sum = 0;
		
		// Iterate till null char so e cover all the chars and doesnt overflow with i+1
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (DecimalNumericalPlace(s[i]) < DecimalNumericalPlace(s[i + 1]))
            {
                sum = sum - DecimalNumericalPlace(s[i]);
            }
            else
            {
                sum += DecimalNumericalPlace(s[i]);
            }
        }
        return sum;
    }
};