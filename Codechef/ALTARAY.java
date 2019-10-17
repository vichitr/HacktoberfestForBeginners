import java.util.*;
class DP
{
    public static void main(String args[])
     {
         Scanner sc=new Scanner(System.in);
         int t=sc.nextInt();
         if(t>10 || t<1)
         {
             return ;
         }
         for(int i=1;i<=t;i++)
         {
             int n=sc.nextInt();
             if(n<1 || n>100000)
             return;
             long a[]=new long[n];
             for(int j=0;j<n;j++)
             {
                 
                 a[j]=sc.nextInt();
                 if(a[j]>(long)Math.pow(10,9) || a[j]<-(long)Math.pow(10,9))
                 return;
             }
             int length[]=new int[n];
             length[n-1]=1;
             count(a,length,a.length-2);
             for(int j=0;j<n;j++)
             System.out.print(length[j]+" ");
             System.out.println();
         }
     }
    static void count(long a[],int length[],int i)
     {
         if(i<0)
         return;
         
         if(a[i]*a[i+1]<0) 
         length[i]=length[i+1]+1;
         if(a[i]*a[i+1]>0)
         length[i]=1;
         count(a,length,i-1);
     }
}     
    