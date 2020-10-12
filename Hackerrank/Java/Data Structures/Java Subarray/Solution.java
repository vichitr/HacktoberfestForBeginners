import java.util.Scanner;

class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int length = in.nextInt();
        int[] array = new int[length];

        for (int i = 0; i < length; i++) {
            array[i] = in.nextInt();
        }

        in.close();

        int negativeSubarrays = 0;
        /* Loop through all length 1 subarrays, then length 2, and so on,
         * checking if each one is negative */
        for (int subLength = 1; subLength <= length; subLength++) {
            for (int start = 0; start <= length - subLength; start++) {
                int subarraySum = 0;
                for (int i = start; i < start + subLength; i++) {
                    subarraySum += array[i];
                }
                if (subarraySum < 0) {
                    negativeSubarrays++;
                }
            }
        }

        System.out.println(negativeSubarrays);
    }

}
