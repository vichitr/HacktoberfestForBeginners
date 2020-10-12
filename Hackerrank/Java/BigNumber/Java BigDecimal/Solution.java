/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.math.BigDecimal;
import java.util.*;
class Solution{
    public static void main(String []args){
        //Input
        Scanner sc= new Scanner(System.in);
        int n=sc.nextInt();
        String []s=new String[n+2];
        for(int i=0;i<n;i++){
            s[i]=sc.next();
        }
        sc.close();
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

        /*
         * 1) From Arrays.sort() doc:
         *        "This sort is guaranteed to be stable: equal elements
         *         will not be reordered as a result of the sort."
         * 2) From BigDecimal.compareTo() doc:
         *        "Two BigDecimal objects that are equal in value but have
         *         a different scale (like 2.0 and 2.00) are considered equal
         *         by this method."
         *
         * These two conditions together mean that this lambda expression
         * satisfies the problem's ordering specifications. Also note that
         * we need to use the bounded version of Arrays.sort(), because the
         * array is initialized too big, and thus includes two null strings.
         */

        Arrays.sort(s, 0, n, (String s1, String s2)
            -> (new BigDecimal(s2)).compareTo(new BigDecimal(s1)));

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
        //Output
        for(int i=0;i<n;i++)
        {
            System.out.println(s[i]);
        }
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
