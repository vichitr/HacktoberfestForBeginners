class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        while(x){
            int d = x%10;
            rev = rev*10 + d;
            x = x/10;
        }
        return ((rev<INT_MIN || rev>INT_MAX)? 0: rev);
    }
};
