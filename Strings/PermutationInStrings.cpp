
// 567. Permutation in String
// Medium

// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

 

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
 

// Constraints:

// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.

class Solution {
public:
bool check_equall(int arr1[26], int arr2[26])
{
    for(int i = 0; i < 26; i++)
    {
        if(arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {
        //find the length of string 1
        int l1 = s1.length();
        //find the length of string 2
        int l2 = s2.length();

        //Take two arrays of size 26 for string s1 and string s2 respectively 

        int count1[26];
        //initially  initialise zero with all indexes
        for(int i = 0; i < 26; i++)
        {
            count1[i] = 0;
        }

        //similar as first string

        int count2[26];
        for(int i = 0; i < 26; i++)
        {
            count2[i] = 0;
        }

        // Now count the total number of occurance of string 1 
        for(int i = 0; i < l1; i++)
        {
            int index = s1[i] - 'a';
            count1[index]++;
        }

         // Now count the total number of occurance of string 2 and compare with both arrays
         //Firstly make the windows size as equall to string s1
         int i = 0;
         int window = l1;
         while(i < window && i < l2)
         {
             int index = s2[i] - 'a';
             count2[index]++;
             i++;
         }

         //Now compare the both array i.e count1 and count2
         if(check_equall(count1 , count2))
         {
             return true;
         }


         //Now check rest of the elements in string s2
         //Before i move next elemnts of the string i have to delete the previous one
         while(i < l2)
         {
             char ch1 = s2[i];
             int index1 = ch1 - 'a';
             count2[index1]++;
             
             // Remove the number of occurance of first windows of first elements
            char ch2 = s2[i - window];
             int index2 = ch2 - 'a';
            count2[index2]--;
             i++;

         if(check_equall(count1 , count2))
         {
            return true;
         }

        }
        return false;
    }
};