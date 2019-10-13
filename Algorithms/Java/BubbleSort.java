import java.util.Scanner;

public class Bubblesort 
{
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        int i, j, n, a[], temp;
        System.out.print("Enter value of n: ");
        n = s.nextInt();
        a = new int[n];
        System.out.println("Enter " + n + "values");
        for(i=0; i<n; i++)
        {
            a[i] = s.nextInt();
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n-1; j++)
            {
                if(a[j] > a[j+1])
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
        for(i=0; i<n; i++)
        {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }
}

/***********************************************************************************
Worst and Average Case Time Complexity: O(n*n). (When array is reverse sorted.)

Best Case Time Complexity: O(n). (Best case occurs when array is already sorted.)
***********************************************************************************/
