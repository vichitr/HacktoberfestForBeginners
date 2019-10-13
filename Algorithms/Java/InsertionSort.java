import java.util.Scanner;

public class InsertionSort 
{
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        int i, j, temp=0, a[], n, ptr;
        System.out.print("Enter value of n : ");
        n = s.nextInt();
      
        a = new int[n+1];
        a[0]=-99999;
        System.out.println ("Please enter " +n +" values in sorted order");
        for(i=1; i<=n; i++)
        {
            a[i] = s.nextInt();
        }
        for(i=2; i<=n; i++)
        {
            temp = a[i];
            ptr = i-1;
            while(temp < a[ptr])
            {
                a[ptr+1] = a[ptr];
                ptr--;
            }
            a[ptr+1] = temp;
        }
        
        System.out.println();
        for(i=1; i<n; i++)
        {
            System.out.print(a[i] + " ");
        }
    }
}

/***********************************************************************************

Time Complexity : O(n^2)

***********************************************************************************/
