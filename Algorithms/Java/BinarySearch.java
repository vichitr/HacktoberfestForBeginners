import java.util.Scanner;

public class BinarySearch 
{
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        int i, j, mid=0, a[], n, search, loc=-1;
        System.out.print("Enter value of n : ");
        n = s.nextInt();
      
        a = new int[n];
        
        System.out.println ("Please enter " +n +" values in sorted order");
        for(i=0; i<n; i++)
        {
            a[i] = s.nextInt();
        }
        System.out.print ("Please enter element to be seached : ");
        search = s.nextInt();
        i = 0; j = n-1;
        while(i<=j)
        {
            mid = (i+j)/2;
            if( search > a[mid] )
            {
                i  = mid + 1;
                
            }
            else if( search < a[mid] )
            {
                j = mid - 1;
            }
            else if( search == a[mid])
            {
                loc = mid;
                break;
            }
        }
        if(loc == -1)
        {
            System.out.println(search + " not present in the array");
        }
        else
        {
            System.out.println(search + " found at location " + loc);
        }

    }
}


/**********************************************************************************

Time Complexity : O(logn))

**********************************************************************************/
