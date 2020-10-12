import java.util.BitSet;
import java.util.Scanner;

class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt();   // size of each bitset
        int M = in.nextInt();   // number of operations to perform

        BitSet b1 = new BitSet(N);
        BitSet b2 = new BitSet(N);

        for (int i = 0; i < M; i++) {
            String operation = in.next();
            int operand1 = in.nextInt();
            int operand2 = in.nextInt();

            switch (operation) {
                case "AND":
                    if (operand1 == 1) b1.and(b2);
                    else b2.and(b1);
                    break;
                case "OR":
                    if (operand1 == 1) b1.or(b2);
                    else b2.or(b1);
                    break;
                case "XOR":
                    if (operand1 == 1) b1.xor(b2);
                    else b2.xor(b1);
                    break;
                case "FLIP":
                    if (operand1 == 1) b1.flip(operand2);
                    else b2.flip(operand2);
                    break;
                case "SET":
                    if (operand1 == 1) b1.set(operand2);
                    else b2.set(operand2);
                    break;
                default:
                    System.out.println("Invalid operation");
            }

            System.out.println(b1.cardinality() + " " + b2.cardinality());
        }

        in.close();
    }

}
