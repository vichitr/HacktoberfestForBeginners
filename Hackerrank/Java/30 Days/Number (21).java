import java.util.Scanner;

class Solution {

    /* Sorts the argument array via bubble sort (O(n^2) time, O(1) space)
     * and returns the number of swaps performed. */
    private static int bubbleSort(int[] arr) {
        int totalSwaps = 0;

        for (int i = 0; i < arr.length; i++) {
            int prevTotalSwaps = totalSwaps;

            for (int j = 0; j < arr.length - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr, j, j + 1);
                    totalSwaps++;
                }
            }

            /* If no elements were swapped this iteration, sorting is done */
            if (prevTotalSwaps == totalSwaps) {
                break;
            }
        }

        return totalSwaps;
    }

    /* Swaps the elements at the specified indices in the specified array. */
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        /* Read in the array and its size */
        Scanner in = new Scanner(System.in);
        int length = in.nextInt();
        int[] arr = new int[length];
        for(int i = 0; i < length; i++){
            arr[i] = in.nextInt();
        }
        in.close();

        /* Sort the array and print results */
        int numSwaps = bubbleSort(arr);
        System.out.println("Array is sorted in " + numSwaps + " swaps.");
        System.out.println("First Element: " + arr[0]);
        System.out.println("Last Element: " + arr[arr.length - 1]);
    }

}
