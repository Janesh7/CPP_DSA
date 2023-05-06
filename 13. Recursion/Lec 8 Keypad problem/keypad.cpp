class Solution {
private:
    void solve(string digit, string output, int index, vector<string>& ans, string mapping[] ) {
        
        //base case
        if(index >= digit.length()) {
            ans.push_back(output);
            return;
        }

        // We need index so subtract from '0' to get it 
        int number = digit[index] - '0';
        // Get the whole string which is mapped to the number for Ex. 2 -> 'abc'
        string value = mapping[number];


        // Traverse through the whole string, 1 by 1 add each and solve and at the last remove the element (backtrack) and continue the for loop as we want other char unique values as well, See diagram in the Recursion Lec 8 video 
        for(int i=0; i<value.length(); i++) {
            output.push_back(value[i]);
            solve(digit, output, index+1, ans, mapping);
            output.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)
            return ans;
        string output;
        int index = 0;
        // 0 and 1 doesnt have any mappings in the phone 
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};