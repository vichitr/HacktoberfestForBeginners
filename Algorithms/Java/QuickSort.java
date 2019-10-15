import java.util.Scanner;

public class QuickSort
{

    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        int i, n, a[];
        System.out.print("Enter value of n: ");
        n = s.nextInt();
        a = new int[n];
        System.out.println("Enter " + n + " values");
        for(i=0; i<n; i++)
        {
            a[i] = s.nextInt();
        }
		
        quickSort(a,0,a.length-1);
		
        for(i=0; i<n; i++)
        {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }
	
	public static void quickSort(int[] array, int low, int high){
		int i, j, temp, middle, pivot;
		middle=low+(high-low)/2;
		pivot=array[middle];
		i=low;
		j=high;
		while(i<=j){
			while(array[i]<pivot){
				i++;
			}
			while(array[j]>pivot){
				j--;
			}
			if(i<=j){
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
				i++;
				j--;
			}
		}
		if(low<j){
			quickSort(array,low,j);
		}
		if(high>i){
			quickSort(array,i,high);
		}
	}
    
}

/*****************************************************************************************

Time Complexity : O(n^2)

*****************************************************************************************/
