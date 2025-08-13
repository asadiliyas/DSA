class Solution {
public:
    bool isPowerOfThree(int n) {
        long long num = 1;
        while(num < INT_MAX && num <= n){
            if(num == n){
                return true;
            }

            num *= 3;
        }
        return false;
    }
};
