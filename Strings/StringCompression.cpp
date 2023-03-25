class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int ansIndex = 0;
        int n = chars.size();

        while (i<n){
            int j = i+1;
            while (j<n && chars[i] == chars[j]){
                j++;
            }
            //either traversed the whole or different char encountered

            // stiore the oldchar
            chars[ansIndex++] = chars[i]; // increment the index for final arr
            int count = j-i; // count the number of chars
            if (count >1) {
                string cnt = to_string(count);
                for (char ch: cnt){ // for double digits
                    chars[ansIndex++] = ch;
                }
            } 
            i = j;
        }
        return ansIndex;
    }
};