/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.io.*;
import java.lang.reflect.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

class Add {
    
    void add(int... args) {
        if (args == null || args.length == 0) return;
        
        int sum = 0;
        for (int i = 0; i < args.length; i++) {
            sum += args[i];
            
            System.out.print(args[i]);
            if (i != args.length - 1) System.out.print("+");
            else System.out.print("=");
        }
        System.out.println(sum);
    }
    
}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */

public class Solution {

    public static void main(String[] args) {
       try{
            BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
            int n1=Integer.parseInt(br.readLine());
            int n2=Integer.parseInt(br.readLine());
            int n3=Integer.parseInt(br.readLine());
            int n4=Integer.parseInt(br.readLine());
            int n5=Integer.parseInt(br.readLine());
            int n6=Integer.parseInt(br.readLine());
            Add ob=new Add();
            ob.add(n1,n2);
            ob.add(n1,n2,n3);
            ob.add(n1,n2,n3,n4,n5);	
            ob.add(n1,n2,n3,n4,n5,n6);
            Method[] methods=Add.class.getDeclaredMethods();
            Set<String> set=new HashSet<>();
            boolean overload=false;
            for(int i=0;i<methods.length;i++)
            {
                if(set.contains(methods[i].getName()))
                {
                    overload=true;
                    break;
                }
                set.add(methods[i].getName());
                
            }
            if(overload)
            {
                throw new Exception("Overloading not allowed");
            }
            }
            catch(Exception e)
            {
                e.printStackTrace();
            }
        }
        
    
    

}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
