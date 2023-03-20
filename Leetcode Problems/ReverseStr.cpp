class Solution {
public:
    void reverseString(vector<char>& sr) {
        int s=0;
        int e = sr.size()-1;

        while(s<e) {
            swap(sr[s++], sr[e--]);
        }
    }
};