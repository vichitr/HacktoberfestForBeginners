class Solution {
    public int mySqrt(int x) {
        if (x == 0) return 0;

        double myX = x;

        // Heron's method to find a square root of the given number (myX here)
        double result = myX;
        for (int i = 0; i <= 20; i++) {
            result = (result + myX / result) / 2;
        }

        return (int)result; // This truncates decimal part
    }
}
