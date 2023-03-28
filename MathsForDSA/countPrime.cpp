class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> num (n+1, true);
        num[0] = num [1] = false;

        for (int i =2;i<n;i++){
            if (num[i]){
                count++;
                for (int j =i*2;j<n;j=j+i)
                    num[j] = false;
            }
        }
        return count;
    }
};