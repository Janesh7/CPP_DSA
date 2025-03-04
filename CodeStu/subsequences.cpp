// Subsequences of String


// Problem Statement
// Suggest Edit
// You are given a string 'STR' containing lowercase English letters from a to z inclusive. Your task is to find all non-empty possible subsequences of 'STR'.
// A Subsequence of a string is the one which is generated by deleting 0 or more letters from the string and keeping the rest of the letters in the same order.
// Detailed explanation ( Input/output format, Notes, Images )

// Constraints:
// 1 <= T <= 10 
// 1 <=  |STR| <= 16

// Where |STR| represents the length of the string 'STR'.

// Time Limit: 1 sec
// Sample Input 1:
// 1 
// abc
// Sample Output 1:
// a ab abc ac b bc c
// Explanation Of Sample Input 1:
// All possible subsequences of abc are :  
// “a” , “b” , “c” , “ab” , “bc” , “ac”, “abc”
// Sample Input 2:
// 1
// bbb
// Sample Output 2:
// b b b bb bb bb bbb


void solve(vector<string>& ans, string str, string output, int i) {
    //base case
    if(i>=str.length()) {
        // If the index goes out then save the outout and return
        if(output.length()>0)
        ans.push_back(output);
        return ;
        }
    
    //exclude
    solve(ans, str, output, i+1);
    //include
    output.push_back(str[i]);
    solve(ans, str, output, i+1);
}

vector<string> subsequences(string str){
	
	vector<string> ans;
    string output = "";
    solve(ans,str,output,0);
    return ans;
	
}
