// Minimum Cost To Make String Valid

// Contributed by
// Arshit Babariya
// Medium
// yellow-spark
// 80/80
// 20 mins
// 80 %


// 115 upvotes
// Problem Statement
// Suggest Edit
// Ninja has been given a string ‘STR’ containing either ‘{’ or ‘}’. 'STR’ is called valid if all the brackets are balanced. Formally for each opening bracket, there must be a closing bracket right to it.
// For Example:
// “{}{}”, “{{}}”, “{{}{}}” are valid strings while “}{}”, “{}}{{}”, “{{}}}{“ are not valid strings.
// Ninja wants to make ‘STR’ valid by performing some operations on it. In one operation, he can convert ‘{’ into ‘}’ or vice versa, and the cost of one such operation is 1.
// Your task is to help Ninja determine the minimum cost to make ‘STR’ valid.
// For Example:
// Minimum operations to make ‘STR’ =  “{{“ valid is 1.
// In one operation, we can convert ‘{’ at index ‘1’ (0-based indexing) to ‘}’. The ‘STR’ now becomes "{}" which is a valid string.

// Note:
// Return -1 if it is impossible to make ‘STR’ valid.
// Detailed explanation ( Input/output format, Notes, Images )
// keyboard_arrow_down
// Constraints :
// 1 <= T <= 100
// 0 <= |STR| <= 10^5
// STR[i] = ‘{’ or ‘}’

// Time Limit: 1 sec 
// Sample Input 1:
// 2
// {{{}
// {{}{}}
// Sample Output 1:
// 1
// 0
// Explanation For Sample Input 1:
// For the first test case:
// The two valid strings that can be obtained from  ‘STR’ using minimum operations “{{}}”   and “{}{}”. Ninja can transform ‘STR’ to “{{}}” by performing the following operations:
// Convert ‘{’ at index 2 to ‘}’.

// Ninja can transform ‘STR’ to “{}{}” by performing the following operations:
// Convert ‘{‘ at index 1 to ‘}’.
// The minimum number of operations in transforming ‘STR’ to either of the two valid strings is 1.So, the total cost is 1.

// For the second test case:
// Given ‘STR’ is already valid so the minimum number of 
// operations required is 0.
// So, the total cost is 0.
// Sample Input 2:
// 3
// {}}{}}
// {{{{
// {{{}}
// Sample Output 2:
// 1
// 2
// -1



#include <stack>
int findMinimumCost(string str) {

  // odd condition
  if (str.length() % 2 == 1) {
    return -1;
  }

  stack<char> s;
  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];

    if (ch == '{')
      s.push(ch);
    else {
      // ch is closed brace
      if (!s.empty() && s.top() == '{') {
        s.pop();
      } else {
        s.push(ch);
      }
    }
  }

  // stack contains invalid expression
  int a = 0, b = 0;
  while (!s.empty()) {
    if (s.top() == '{') {
      b++;
    } else {
      a++;
    }
    s.pop();
  }

  int ans = (a + 1) / 2 + (b + 1) / 2;
  return ans;
}