import java.util.*;
class divisibleSumPairs
{
public static void main(String[] args)
{
Scanner sc = new Scanner (System.in);
int n = sc.nextInt();
int k = sc.nextInt();
int ar[] = new int [n];
int i;
for (i = 0; i < n; i++)
{
ar[i] = sc.nextInt();
}
System.out.println(divisibleSumPairs(ar, n, k));

int divisibleSumPairs(int ar[], int n, int k) {
        int result = 0;
        int i , j;
        for (i = 0; i < n; i++){
            for (j = i + 1; j < n; j++){
                    if ((ar[i] + ar[j]) % k == 0)
                        result++; 
            }
        }
        return result;

    }
sc.close();
}
}