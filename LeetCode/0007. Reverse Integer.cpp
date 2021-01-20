/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/


class Solution {
public:
    int reverse(int x) {
        int tmp=x, len=0;
        while(tmp){
            tmp /= 10;
            len++;
        }
        tmp=x;
        long long int ans=0;
        while(tmp){
            ans += (long long int)(pow(10, --len))*(tmp%10);
            //cout<< ans<< endl;
            if (ans > INT_MAX || ans < INT_MIN) return 0;
            tmp /= 10;
        }
        //if(x<0) ans *= -1;
        return ans;
    }
};