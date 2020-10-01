import java.lang.*;
import java.util.*;
class SearchingTypes
{
        public static void main(String args[])
        {
            Scanner scan=new Scanner(System.in);
            int size;
            System.out.print("Enter the size of your array: ");
            size=scan.nextInt();
            int[] arr=new int[size];
            for(int i=0;i<size;i++)
            {
                System.out.print("Enter the element: ");
                arr[i]=scan.nextInt();
            }
            System.out.print("Enter <1> to use Linear Search and <2> for Binary Search and <0> to exit: ");
            int ch=scan.nextInt();
            int ele,flag;
            while(ch!=0){
            switch(ch){
                case 1: System.out.print("Enter the value you want to search: ");
                        ele=scan.nextInt();
                        flag=0;
                        for(int i:arr){
                            if(i==ele) {System.out.println("Match found!"); flag=1;}
                            break;
                        }
                        if(flag==0) System.out.println("Match not found");
                        break;
                case 2: System.out.print("Binary Search needs sorted array. Is the array sorted? [Y/N]: ");
                        String ans=scan.next();
                        if(ans.equalsIgnoreCase("N")){
                            for(int i=0;i<size-1;i++){
                                for(int j=i;j<size;j++){
                                    if(arr[i]>arr[j]){
                                        int temp=arr[i];
                                        arr[i]=arr[j];
                                        arr[j]=temp;
                                    }
                                }
                            }
                            System.out.println("Array has been sorted");
                            for(int x:arr) System.out.print(x+"\t");
                        }
                        System.out.print("\nEnter the value you want to search: ");
                        ele=scan.nextInt();
                        flag=0;
                        int first=0,last=size-1;
                        int mid=(first+last)/2;
                        while(first<=last){
                            if(arr[mid]==ele) {
                                flag=1; break;
                            }
                            else if(ele<arr[mid]) last=mid-1;
                            else first=mid+1;
                            mid=(first+last)/2;
                        }
                        if(flag==1) System.out.println("Match found!");
                        else System.out.println("Match not found");
                        break;
                default: System.out.println("Invalid choice.");
            }
            System.out.print("Enter <1> to use Linear Search and <2> for Binary Search and <0> to exit: ");
            ch=scan.nextInt();
        }
    }
}