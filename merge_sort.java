
import java.util.*;
public class Merge_sort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
     Scanner in=new Scanner(System.in);
     int n=in.nextInt();
     int m=in.nextInt();
     int arr1[]=new int[n];
     int arr2[]=new int[m];
     for (int i=0;i<n;i++)
    	 arr1[i]=in.nextInt();
     for (int i=0;i<m;i++)
    	 arr2[i]=in.nextInt();
     int arr3[]=new int[n+m];
     int l=0,b=0,k=0;
     while(l<n&&b<m)
     {
    	 if (arr1[l]<=arr2[b])
    	 {
    		 arr3[k]=arr1[l];
    		 l++;
    		 k++;
    	 }
    	 else
    	 {
    		 arr3[k]=arr2[b];
    		 b++;
    		 k++;
    	 }
     }
     if (l==n)
     {
    	 while(b<m)
    		 {arr3[k]=arr2[b];b++;k++;}
     }
     if (b==m)
     {
    	 while(l<n)
    		 {arr3[k]=arr1[l];l++;k++;}
     }
     for (int i=0;i<m+n;i++)
    	 System.out.println(arr3[i]);
	}

}
