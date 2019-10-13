public class CocktailSort 
{
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        int i, j, start=0, n, end, flag;
        System.out.print("Enter value of n : ");
        n = s.nextInt();
        int a[] = new int[n];
        System.out.println ("Please enter " +n +" values");
        for(i=0; i<n; i++)
        {
            a[i] = s.nextInt();
        }
        flag = 0;
        end = n;
        while(start <= end)
        {
            for(i=start; i<end-1; i++)
            {
                if(a[i]>a[i+1])
                {   
                    int temp =a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                    flag=1;
                }
            }
            if(flag==0)
            {
                break;
            }
            flag=0;
            end = end-1;
        
            for(i=end; i>start; i--)
            {
                if(a[i]<a[i-1])
                {
                    int temp = a[i];
                    a[i] = a[i-1];
                    a[i-1]= temp;
                    flag=1;
                }
            }
            if(flag==0)
            {
                break;
            }
            start = start+1;
            flag=0;
        }
        
        System.out.println();
        for(i=0; i<n; i++)
        {
            System.out.print(a[i] + " ");
        }
    }
}

/******************************************************************************
                                  COMPLEXITY
Worst and Average Case Time Complexity: O(n*n).

Best Case Time Complexity: O(n). (when array is already sorted.)
*******************************************************************************/
    
    

