import java.util.Scanner;

public class SelectionSort
{

    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        int i, j, n, a[], temp, loc, min;
        System.out.print("Enter value of n: ");
        n = s.nextInt();
        a = new int[n];
        System.out.println("Enter " + n + "values");
        for(i=0; i<n; i++)
        {
            a[i] = s.nextInt();
        }
        for(i=0; i<n-1; i++)
        {
            loc = i;
            min = a[i];
            for(j=i+1; j<n; j++)
            {
                if(min > a[j])
                {
                    min = a[j];
                    loc = j;
                }
            }
            temp = a[i];
            a[i] = a[loc];
            a[loc] = temp;
        }
        for(i=0; i<n; i++)
        {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }
    
}

/*****************************************************************************************

Time Complexity : O(n^2)

*****************************************************************************************/
