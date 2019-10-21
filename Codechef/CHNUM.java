import java.util.*;
import java.lang.Math;
class Byteland
{
    public static void main(String args[])
    {
     Scanner sc=new Scanner(System.in);
     int t=sc.nextInt(),j=0;
     if(t<1 || t>20)
     return;
     int c[][]=new int[t][2];
     int count1=0,count2=0,count3=0,max=0,min=0,sum=0;
     for(int i=1;i<=t;i++)
      {  
         max=0;min=0;count1=0;count2=0;count3=0;
         int n=sc.nextInt();
         
         if(n<1 || n>100000)
         continue;
         sum+=n;
         int a[]=new int[n];
         
         for( j=0;j<n;j++)
         {
         a[j]=sc.nextInt();
         
         if(Math.abs(a[j])<1 || Math.abs(a[j])>Math.pow(10,9))
         continue;
         }
        
         
         for(j=0;j<n;j++)
         
         if(a[j]>0)
         count1++;
         
         else if(a[j]<0)
         count2++;
         
         else count3++;
         
         if(count1!=0 && count2!=0)
        { 
         if(count3!=0)
         {
         if(count1>count2)
         {max=count1+count3;
          min=count2;}
          else
          {max=count2+count3;
           min=count1;
          }
         }
          else
          {
          if(count1>count2)
          {
              max=count1;
              min=count2;
          }
          else
          {
              max=count2;
              min=count1;
          }
          }
        }
        else 
        {
          if(count1!=0)
          {
              max=count1;min=count1;
          }
          if(count2!=0)
          {
              max=count2;min=count2;
          }
          
        }
         
         c[i-1][0]=max;
         c[i-1][1]=min;
         
        }
        if(sum<=500000)
        for(int i=0;i<t;i++)
        System.out.println(c[i][0]+" "+c[i][1]);
     }
}