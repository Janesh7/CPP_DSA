// LC problem no 1281 - Given an integer number n, return the difference between the product of its digits and the sum of its digits.
class Solution {
public:
    int subtractProductAndSum(int n) {
        
        int prod = 1;
        int sum = 0;
        
        while(n!=0) { //Till the number isnt 0
            
            int digit = n%10; // To get the last digit 
            prod = prod * digit;
            sum = sum + digit;
            
            n = n/10; // Divide to remove the last digit from number(implicity type casted to int)
        }
        
        int answer = prod - sum;
        return answer;
    }
};