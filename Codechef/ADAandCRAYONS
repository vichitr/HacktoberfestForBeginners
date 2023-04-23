/*Ques: https://www.codechef.com/submit/ADACRA?tab=statement */
import java.util.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ada_and_crayons
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc= new Scanner(System.in);
		int t= sc.nextInt();
		while(t-->0){
		   int count_u=0,count_d=0;
		    String s= sc.next();
		    int x= s.length();
		    for(int i=0;i<x-1;i++){
		        if(s.charAt(i)=='U' && s.charAt(i+1)!='U')
		        count_u++;
		        else if(s.charAt(i)=='D' && s.charAt(i+1)!='D')
		        count_d++;
		    }
		    if(s.charAt(s.length()-1)=='U')
		    count_u++;
		    else
		    count_d++;
		    
		    if(count_d<=count_u)
		    System.out.println(count_d);
		    else
		    System.out.println(count_u);
		}
        sc.close();
	}
}
