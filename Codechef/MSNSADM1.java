//MSNSADM1 - codechef

import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc= new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0){
			int n=sc.nextInt();
			int a[] = new int[n];
			int b[] = new int[n];
			int max=0,x=0;
			for(int i=0;i<n;i++){
				a[i]=sc.nextInt();
			}
			for(int i=0;i<n;i++){
				b[i]=sc.nextInt();
			}
			for(int i=0;i<n;i++){
				x=(a[i]*20)-(b[i]*10);
				if(x<0){x=0;}
				if(max<x){max=x;}
			}
			System.out.println(max);
		}
	}
}
